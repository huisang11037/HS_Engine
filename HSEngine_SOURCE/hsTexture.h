#pragma once
#include "hsResource.h"


namespace hs::graphcis
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		static Texture* Create(const std::wstring& name, eTextureType type, UINT width, UINT height);

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		void SetWidth(UINT width) { mWidth = width; }
		void SetHeight(UINT height) { mHeight = height; }
		void SetTextureType(eTextureType type) { mType = type; }
		UINT GetWidth() const { return mWidth; }
		UINT GetHeight() const  { return mHeight; }
		HDC GetHdc() const  { return mHdc; }
		eTextureType GetTextureType() const { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }
		bool IsAlpha() const { return mbAlpha; }

	private:
		bool mbAlpha;
		eTextureType mType;
		Gdiplus::Image* mImage;
		HBITMAP mBitmap;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}