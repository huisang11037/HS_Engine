#include "hsPlayScene.h"
#include "hsGameObject.h"
#include "hsPlayer.h"
#include "hsTransform.h"
#include "hsSpriteRenderer.h"
#include "hsInput.h"
#include "hsTitleScene.h"
#include "hsSceneManager.h"
#include "hsObject.h"
#include "hsTexture.h"
#include "hsResources.h"

namespace hs
{
	PlayScene::PlayScene()
		: bg(nullptr)
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//게임오브젝트 만들기전에 리소스들 전부 Load해두면 좋다.
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG");
		sr->SetTexture(bg);

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::KEY_N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}