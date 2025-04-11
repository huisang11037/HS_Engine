#include "hsGameObject.h"
#include "hsInput.h"

namespace hs
{
	GameObject::GameObject()
	{
		mX = 0.0f;
		mY = 0.0f;
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::KEY_A)) {
			mX -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::KEY_D)) {
			mX += 0.01f;
		}
		if (Input::GetKey(eKeyCode::KEY_W)) {
			mY -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::KEY_S)) {
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc) const
	{
		Rectangle(hdc, 0 + mX, 0 + mY, 100 + mX, 100 + mY);
	}
}