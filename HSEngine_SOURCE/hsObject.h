#pragma once
#include "hsComponent.h"
#include "hsGameObject.h"
#include "hsLayer.h"
#include "hsScene.h"
#include "hsSceneManager.h"
#include "hsTransform.h"


namespace hs::object
{
	template <typename T>
	static T* Instantiate(hs::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(hs::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);
		tr->SetName(L"TR");

		return gameObject;
	}

	static void Destory(GameObject* obj)
	{
		obj->Death();
	}
}