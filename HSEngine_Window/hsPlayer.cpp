#include "hsPlayer.h"
#include "hsInput.h"
#include "hsTransform.h"
#include "hsTime.h"

namespace hs
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		if (Input::GetKey(eKeyCode::KEY_RIGHT))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}