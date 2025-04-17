#pragma once
#include "hsSceneManager.h"
#include "hsPlayScene.h"
#include "hsTitleScene.h"

namespace hs
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"PlayScene");
	}
}