#include "hsTexture.h"
#include "hsApplication.h"
#include "hsResources.h"

extern hs::Application application;

namespace hs::graphics
{
	Texture* Texture::Create(const std::wstring& name, eTextureType type, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		assert(!image);

		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);
		image->SetTextureType(type);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		Rectangle(image->mHdc, -1, -1, image->GetWidth() + 1, image->GetHeight() + 1);
		SelectObject(hdc, oldBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		Resources::Insert(name + L"Image", image);

		return image;
	}
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mbAlpha(false)
		, mType(eTextureType::None)
		, mImage(nullptr)
		, mBitmap(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
	{
	}

	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{

		std::wstring ext
			= path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP
				, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return E_FAIL;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			if (info.bmBitsPixel == 32)
				mbAlpha = true;
			else if (info.bmBitsPixel == 24)
				mbAlpha = false;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);

		}
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			if (mImage == nullptr)
				return E_FAIL;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}
}