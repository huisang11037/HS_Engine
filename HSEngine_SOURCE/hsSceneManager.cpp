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
	void SceneManager::Release()
	{
		for (auto& iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mCurrentScene) mCurrentScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

		if (iter == mScenes.end()) return nullptr;

		mCurrentScene = iter->second;
		mCurrentScene->OnEnter();

		return iter->second;
	}
}