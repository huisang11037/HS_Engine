#include "hsPlayScene.h"
#include "hsGameObject.h"
#include "hsPlayer.h"
#include "hsTransform.h"
#include "hsSpriteRenderer.h"
#include "hsInput.h"
#include "hsTitleScene.h"
#include "hsSceneManager.h"
#include "hsObject.h"

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
			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\HSEngine\\Resources\\CloudOcean.png");
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
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}