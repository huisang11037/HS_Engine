#include "hsPlayScene.h"
#include "hsGameObject.h"
#include "hsPlayer.h"
#include "hsTransform.h"
#include "hsSpriteRenderer.h"
#include "hsInput.h"
#include "hsTitleScene.h"
#include "hsSceneManager.h"

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
		{
			bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPosition(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\HSEngine\\Resources\\CloudOcean.png");


			AddGameObject(bg, eLayerType::BackGround);
		}
		{
			Player* player = new Player();

			Transform* tr
				= player->AddComponent<Transform>();
			tr->SetPosition(Vector2(100, 100));

			tr->SetName(L"TR");
			SpriteRenderer* sr
				= player->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\HSEngine\\Resources\\Player1.png");
			AddGameObject(player, eLayerType::Player);
		}
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
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}