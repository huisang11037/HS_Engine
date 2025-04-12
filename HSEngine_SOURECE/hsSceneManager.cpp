#include "hsSceneManager.h"

namespace hs
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mCurrentScene = nullptr;

	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		mCurrentScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mCurrentScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mCurrentScene->Render(hdc);
	}
}