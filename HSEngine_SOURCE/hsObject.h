#pragma once
#include "hsComponent.h"
#include "hsGameObject.h"
#include "hsLayer.h"
#include "hsScene.h"
#include "hsSceneManager.h"
#include "hsTransform.h"


namespace hs::object
{
	// 메소드 오버로딩을 통해 다양한 형태의 Instantiate 메소드를 제공
	// 기본적으로 GameObject를 생성하고, 해당 GameObject를 특정 레이어에 추가하는 기능을 수행
	// GameObject의 Transform 컴포넌트를 가져와서 위치를 설정하는 기능도 포함
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
}