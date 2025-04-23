#include "hsAnimation.h"
#include "hsTime.h"
#include "hsGameObject.h"
#include "hsTransform.h"
#include "hsAnimator.h"
#include "hsRenderer.h"
#include "hsCamera.h"

namespace hs
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mIsComplete(false)
    {
    }
    Animation::~Animation()
    {
    }
    HRESULT Animation::Load(const std::wstring& path)
    {
        return E_NOTIMPL;
    }
    void Animation::Update()
    {
        if (mIsComplete) return;

		mTime += Time::DeltaTime();

        if (mAnimationSheet[mIndex].duration < mTime) 
        {
			mTime = 0.0f;
            if (mIndex < mAnimationSheet.size() - 1)
            {
                mIndex++;
            }
            else
            {
				mIsComplete = true;
            }
        }
    }
    void Animation::Render(HDC hdc)
    {
		GameObject* owner = mAnimator->GetOwner();
		Transform* tr = owner->GetComponent<Transform>();
		Vector2 position = tr->GetPosition();
		float rotation = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
		{
			position = renderer::mainCamera->CaluatePosition(position);
		}

		Sprite sprite = mAnimationSheet[mIndex];
		graphcis::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphcis::Texture::eTextureType::Png)
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
					position.x - (sprite.size.x / 2.0f)
					, position.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, /*&imgAttr*/nullptr);
		}
		else if (type == graphcis::Texture::eTextureType::Bmp) 
		{
			HDC imgHdc = mTexture->GetHdc();

			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, position.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, position.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, position.x - (sprite.size.x / 2.0f) + sprite.offset.x
					, position.y - (sprite.size.y / 2.0f) + sprite.offset.y
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
					, imgHdc
					, sprite.leftTop.x
					, sprite.leftTop.y
					, sprite.size.x
					, sprite.size.y
					, RGB(255, 0, 255));
			}
		}
    }
    void Animation::CreateAnimation(const std::wstring& name
        , graphcis::Texture* spriteSheet
        , Vector2 leftTop
        , Vector2 tileSize
        , Vector2 offset
        , UINT spriteLength
        , float duration)
    {
		mTexture = spriteSheet;
		for (UINT i = 0; i < spriteLength; ++i)
		{
            Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (tileSize.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = tileSize;
			sprite.offset = offset;
			sprite.duration = duration;
			mAnimationSheet.push_back(sprite);
		}
    }
    void Animation::Reset()
    {
		mTime = 0.0f;
		mIndex = 0;
		mIsComplete = false;
    }
}