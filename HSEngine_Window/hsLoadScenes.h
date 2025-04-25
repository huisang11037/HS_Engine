#pragma once
#include "hsSceneManager.h"
#include "hsPlayScene.h"
#include "hsTitleScene.h"
#include "hsToolScene.h"

namespace hs
{
	/**
	* @brief 씬을 로드하는 함수입니다. 새로운 씬을 추가할 때마다 이곳에 추가합니다.
	*/
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"TitleScene");

		//SceneManager::CreateScene<ToolScene>(L"ToolScene");
		//SceneManager::LoadScene(L"ToolScene");
	}
}