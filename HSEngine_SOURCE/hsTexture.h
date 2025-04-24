#pragma once
#include "hsResource.h"


namespace hs::graphcis
{
	/**
	* @brief 텍스처인 리소스입니다.
	*/
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		static Texture* Create(const std::wstring& name, UINT width, UINT height);

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		void SetWidth(UINT width) { mWidth = width; }
		void SetHeight(UINT height) { mHeight = height; }
		UINT GetWidth() const { return mWidth; }
		UINT GetHeight() const  { return mHeight; }
		HDC GetHdc() const  { return mHdc; }
		eTextureType GetTextureType() const { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
		bool IsAlpha() const { return mIsAlpha; }

	private:
		bool mIsAlpha;
		eTextureType mType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}