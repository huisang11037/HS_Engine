#include "hsGameObject.h"
#include "hsInput.h"
#include "hsTime.h"

namespace hs
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}
	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
}