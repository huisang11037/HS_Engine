#include "hsScene.h"

namespace hs
{
	Scene::Scene()
		: mLayers{}
	{
		CreateLayers();
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) continue;

			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) continue;

			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) continue;

			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr) continue;

			layer->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* gameObject, const eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}

	void Scene::CreateLayers()
	{
		// 레이어를 최대 16개까지 생성한다.
		// 레이어 타입은 eLayerType 열거형을 사용한다.
		// 각 레이어는 Layer 클래스의 인스턴스이다.
		// 레이어는 std::vector<Layer*> mLayers에 저장된다.
		mLayers.resize((UINT)eLayerType::Max);
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{

	}
}