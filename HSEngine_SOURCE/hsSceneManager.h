#pragma once
#include "hsScene.h"

namespace hs
{
	/**
	* @brief ������ �����ϴ� Ŭ�����Դϴ�. ���� �����ϰ�, �ε��ϰ�, ������Ʈ�ϴ� ����� �����մϴ�.
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
