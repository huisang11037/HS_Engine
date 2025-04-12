#include "hsGameObject.h"
#include "hsInput.h"
#include "hsTime.h"

namespace hs
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		const int SPEED = 300;
		if (Input::GetKey(eKeyCode::KEY_A)) {
			mX -= SPEED * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::KEY_D)) {
			mX += SPEED * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::KEY_W)) {
			mY -= SPEED * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::KEY_S)) {
			mY += SPEED * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc) const
	{
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
		SelectObject(hdc, brush);

		Rectangle(hdc, 0 + mX, 0 + mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}