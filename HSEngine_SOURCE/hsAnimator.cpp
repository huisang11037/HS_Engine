#include "hsAnimator.h"

namespace hs {
	Animator::Animator()
		: Component(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mIsLoop(false)
	{
		// mAnimations는 std::map이며,
		// 애니메이션 이름을 키로 사용하고 Animation 객체를 값으로 사용한다.
	}
	Animator::~Animator()
	{
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();
			if (mActiveAnimation->IsComplete() && mIsLoop)
			{
				mActiveAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(hdc);
		}
	}
	void Animator::CreateAnimation(const std::wstring& name
		, graphcis::Texture* spriteSheet
		, Vector2 leftTop
		, Vector2 tileSize
		, Vector2 offset
		, UINT spriteLength
		, float duration)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation == nullptr)
		{
			animation = new Animation();
			animation->CreateAnimation(name, spriteSheet, leftTop, tileSize, offset, spriteLength, duration);
			animation->SetAnimator(this);

			mAnimations.insert(std::make_pair(name, animation));
		}
		else
		{
			return;
		}
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);
		if (iter != mAnimations.end())
		{
			return iter->second;
		}
		else
		{
			return nullptr;
		}
	}
	void Animator::PlayAnimation(const std::wstring& name, bool isLoop)
	{
		Animation* animation = FindAnimation(name);
		if (animation)
		{
			mActiveAnimation = animation;
			mActiveAnimation->Reset();
			mIsLoop = isLoop;
		}
		else
		{
			return;
		}
	}
}