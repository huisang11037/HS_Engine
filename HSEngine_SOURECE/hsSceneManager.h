#pragma once
#include "hsScene.h"

namespace hs
{
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScenes.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			if (mCurrentScene) mCurrentScene->OnExit();

			auto iter = mScenes.find(name);
			if (iter != mScenes.end())
			{
				mCurrentScene = iter->second;
				mCurrentScene->OnEnter();
				return mCurrentScene;
			}
			return nullptr;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<std::wstring, Scene*> mScenes;
		static Scene* mCurrentScene;
	};
}
