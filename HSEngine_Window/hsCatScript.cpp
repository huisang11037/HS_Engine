#include "hsCatScript.h"
#include "hsInput.h"
#include "hsTransform.h"
#include "hsTime.h"
#include "hsGameObject.h"
#include "hsAnimator.h"
#include "hsObject.h"

namespace hs
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDirection(CatScript::eDirection::End)
		, mDeathTime(0.0f)
		, mPlayer(nullptr)
		, mRadian(0.0f)
		, mDest(Vector2::Zero)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{
		

	}
	void CatScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case hs::CatScript::eState::SitDown:
			sitDown();
			break;
		case hs::CatScript::eState::Walk:
			move();
			break;

		case hs::CatScript::eState::Sleep:
			break;
		case hs::CatScript::eState::LayDown:
			break;
		case hs::CatScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::sitDown()
	{
	}
	void CatScript::move()
	{
	}
	void CatScript::layDown()
	{

	}
	void CatScript::PlayWalkAnimationByDirection(eDirection dir)
	{
	}
	void CatScript::translate(Transform* tr)
	{
	}
}