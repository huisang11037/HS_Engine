#include "hsPlayerScript.h"
#include "hsInput.h"
#include "hsTransform.h"
#include "hsTime.h"
#include "hsGameObject.h"
#include "hsAnimator.h"
#include "hsCat.h"
#include "hsCatScript.h"
#include "hsObject.h"
#include "hsResources.h"
#include "hsCollider.h"
#include "hsRigidbody.h"

namespace hs
{
	PlayerScript::PlayerScript()
		: mState(ePlayerState::Idle)
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
		case hs::PlayerScript::ePlayerState::Idle:
			idle();
			break;
		case hs::PlayerScript::ePlayerState::Walk:
			move();
			break;
		case hs::PlayerScript::ePlayerState::Sleep:
			break;
		case hs::PlayerScript::ePlayerState::GiveWater:
			giveWater();
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
	void PlayerScript::AttackEffect()
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::KEY_RIGHT) || Input::GetKey(eKeyCode::KEY_LEFT) || Input::GetKey(eKeyCode::KEY_UP) || Input::GetKey(eKeyCode::KEY_DOWN))
		{
			mState = ePlayerState::Walk;
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::KEY_RIGHT))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::KEY_LEFT))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::KEY_UP))
		{
			//pos.y -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(0.0f, -200.0f));
		}
		if (Input::GetKey(eKeyCode::KEY_DOWN))
		{
			//pos.y += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(0.0f, 200.0f));
		}
		//tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::KEY_RIGHT) || Input::GetKeyUp(eKeyCode::KEY_LEFT) 
			|| Input::GetKeyUp(eKeyCode::KEY_UP) || Input::GetKeyUp(eKeyCode::KEY_DOWN))
		{
			mState = ePlayerState::Idle;
		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = ePlayerState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{
	}
	void PlayerScript::OnCollisionExit(Collider* other)
	{
		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 300.0f));
	}
}