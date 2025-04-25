#include "hsSceneManager.h"
#include "hsDontDestroyOnLoad.h"

namespace hs
{
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mCurrentScene = nullptr;
	Scene* SceneManager::mDontDestroyOnLoad = nullptr;

	void SceneManager::Initialize()
	{
		mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}
	void SceneManager::Update()
	{
		mCurrentScene->Update();
		mDontDestroyOnLoad->Update();
	}
	void SceneManager::LateUpdate()
	{
		mCurrentScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mCurrentScene->Render(hdc);
		mDontDestroyOnLoad->Render(hdc);
	}
	void SceneManager::Destroy()
	{
		mCurrentScene->Destroy();
		mDontDestroyOnLoad->Destroy();
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

		assert(iter != mScenes.end());

		mCurrentScene = iter->second;
		mCurrentScene->OnEnter();

		return iter->second;
	}
}