#pragma once
#include "hsScene.h"

namespace hs
{
	/**
	* @brief 씬들을 관리하는 클래스입니다. 씬을 생성하고, 로드하고, 업데이트하는 기능을 제공합니다.
	*/
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mCurrentScene = scene;
			scene->Initialize();

			mScenes.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mCurrentScene; }
		static Scene* GetDontDestroyOnLoad() { return mDontDestroyOnLoad; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();

	private:
		static std::map<std::wstring, Scene*> mScenes;
		static Scene* mCurrentScene;
		static Scene* mDontDestroyOnLoad;
	};
}
