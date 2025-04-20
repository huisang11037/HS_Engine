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
		if (mTexture == nullptr) return;

		GameObject* owner = mAnimator->GetOwner();
		Transform* tr = owner->GetComponent<Transform>();
		Vector2 position = tr->GetPosition();

		if (renderer::mainCamera)
		{
			position = renderer::mainCamera->CaluatePosition(position);
		}

        // 알파블렌드 설정
		BLENDFUNCTION blendFunc = {};
		blendFunc.BlendOp = AC_SRC_OVER;
		blendFunc.BlendFlags = 0;
		blendFunc.AlphaFormat = AC_SRC_ALPHA;
		blendFunc.SourceConstantAlpha = 255; // 0 ~ 255 알파값

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		AlphaBlend(hdc, position.x, position.y, sprite.size.x, sprite.size.y
			, imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y
			, blendFunc);
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