#pragma once
#include "hsSceneManager.h"
#include "hsPlayScene.h"

namespace hs
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}