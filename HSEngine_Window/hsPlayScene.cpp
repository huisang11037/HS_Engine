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
#include "hsPlayerScript.h"
#include "hsCamera.h"
#include "hsRenderer.h"
#include "hsAnimator.h"
#include "hsCat.h"
#include "hsCatScript.h"

namespace hs
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(650.0f, 380.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();



		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();

		graphcis::Texture* packmanTexture = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"DownWalk", packmanTexture, Vector2(0.0f, 0.0f)
			, Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"RightWalk", packmanTexture, Vector2(0.0f, 32.0f)
			, Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"UpWalk", packmanTexture, Vector2(0.0f, 64.0f)
			, Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"LeftWalk", packmanTexture, Vector2(0.0f, 96.0f)
			, Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"SitDown", packmanTexture, Vector2(0.0f, 128.0f)
			, Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"Attack", packmanTexture, Vector2(0.0f, 160.0f)
			, Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"SitDown", false);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(45.0f);

		// Cat
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		cat->AddComponent<CatScript>();

		graphcis::Texture* catTex = Resources::Find<graphcis::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		// Cat end

		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"Bubble");
		bgSr->SetTexture(bgTexture);

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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 11);
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