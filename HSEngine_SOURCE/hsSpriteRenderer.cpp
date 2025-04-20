#include "hsSpriteRenderer.h"
#include "hsGameObject.h"
#include "hsTransform.h"
#include "hsTexture.h"
#include "hsRenderer.h"

namespace hs
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{


	}
	void SpriteRenderer::Update()
	{

	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr) assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 position = tr->GetPosition();
		float rotation = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		position = renderer::mainCamera->CaluatePosition(position);

		if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc, position.x, position.y
				, mTexture->GetWidth() * mSize.x * scale.x
				, mTexture->GetHeight() * mSize.y * scale.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Png)
		{
			// 투명화할 색상 지정, 쓰고싶으면 밑에 grapics.DrawImage에 마지막 nullptr 대신 넣으면 된다
			Gdiplus::ImageAttributes imgAttr = {};
			imgAttr.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
			
			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(position.x, position.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-position.x, -position.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					position.x, position.y
					, mTexture->GetWidth() * mSize.x * scale.x
					, mTexture->GetHeight() * mSize.y * scale.y
				)
				, 0, 0
				, mTexture->GetWidth(), mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, /*&imgAttr*/nullptr);
		}
	}
}