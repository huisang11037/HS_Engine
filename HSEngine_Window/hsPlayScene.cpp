#include "hsPlayScene.h"
#include "hsGameObject.h"

namespace hs
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		for (int i = 0; i < 10; ++i)
		{
			GameObject* gameObject = new GameObject();
			gameObject->SetPosition(rand() % 1280, rand() % 720);
			AddGameObject(gameObject);
		}
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}