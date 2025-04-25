#pragma once
#include "hsSceneManager.h"
#include "hsPlayScene.h"
#include "hsTitleScene.h"
#include "hsToolScene.h"

namespace hs
{
	/**
	* @brief ���� �ε��ϴ� �Լ��Դϴ�. ���ο� ���� �߰��� ������ �̰��� �߰��մϴ�.
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