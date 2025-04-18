#include "hsScene.h"

namespace hs
{
	Scene::Scene()
		: mLayers{}
	{
		createLayers();
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
	void Scene::AddGameObject(GameObject* gameObject, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}

	void Scene::createLayers()
	{
		// ���̾ �ִ� 16������ �����Ѵ�.
		// ���̾� Ÿ���� eLayerType �������� ����Ѵ�.
		// �� ���̾�� Layer Ŭ������ �ν��Ͻ��̴�.
		// ���̾�� std::vector<Layer*> mLayers�� ����ȴ�.
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
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