#include "hsGameObject.h"
#include "hsInput.h"
#include "hsTime.h"
#include "hsTransform.h"
#include "hsCollider.h"

namespace hs::object
{
	void Destory(GameObject* gameObject)
	{
		if (gameObject != nullptr)
			gameObject->death();
	}
}

namespace hs
{
	GameObject::GameObject()
		: mState(eState::Active)
		, mComponents{}
		, mLayerType(eLayerType::None)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			delete comp;
			comp = nullptr;
		}
	}
	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Render(hdc);
		}
	}
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}