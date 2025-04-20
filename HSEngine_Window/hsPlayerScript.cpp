#include "hsPlayerScript.h"
#include "hsInput.h"
#include "hsTransform.h"
#include "hsTime.h"
#include "hsGameObject.h"
#include "hsAnimator.h"

namespace hs
{
	PlayerScript::PlayerScript()
		: mState(ePlayerState::SitDown)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		switch (mState)
		{
		case hs::PlayerScript::ePlayerState::SitDown:
			sitDown();
			break;
		case hs::PlayerScript::ePlayerState::Move:
			move();
			break;
		case hs::PlayerScript::ePlayerState::Sleep:
			break;
		case hs::PlayerScript::ePlayerState::Attack:
			break;
		default:
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::sitDown()
	{
		if (Input::GetKey(eKeyCode::KEY_RIGHT))
		{
			mAnimator->PlayAnimation(L"RightWalk", true);
			mState = ePlayerState::Move;
		}
		if (Input::GetKey(eKeyCode::KEY_LEFT))
		{
			mAnimator->PlayAnimation(L"LeftWalk", true);
			mState = ePlayerState::Move;
		}
		if (Input::GetKey(eKeyCode::KEY_UP))
		{
			mAnimator->PlayAnimation(L"UpWalk", true);
			mState = ePlayerState::Move;
		}
		if (Input::GetKey(eKeyCode::KEY_DOWN))
		{
			mAnimator->PlayAnimation(L"DownWalk", true);
			mState = ePlayerState::Move;
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::KEY_RIGHT))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::KEY_LEFT))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::KEY_UP))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::KEY_DOWN))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::KEY_RIGHT) || Input::GetKeyUp(eKeyCode::KEY_LEFT) 
			|| Input::GetKeyUp(eKeyCode::KEY_UP) || Input::GetKeyUp(eKeyCode::KEY_DOWN))
		{
			mState = ePlayerState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
}