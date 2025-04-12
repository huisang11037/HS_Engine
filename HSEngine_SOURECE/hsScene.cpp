#include "hsScene.h"

namespace hs
{
	Scene::Scene()
		: mGameObjects{}
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
	}
	void Scene::Update()
	{
		for (GameObject* gameObject : mGameObjects) {
			gameObject->Update();
		}
	}
	void Scene::LateUpdate()
	{
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObject : mGameObjects) {
			gameObject->Render(hdc);
		}
	}
}