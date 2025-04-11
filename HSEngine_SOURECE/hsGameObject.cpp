#include "hsGameObject.h"
#include "CommonInclude.h"

namespace hs
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			mY -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		Rectangle(hdc, 0 + mX, 0 + mY, 100 + mX, 100 + mY);
	}
}