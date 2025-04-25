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
#include "hsCircleCollider2D.h"
#include "hsBoxCollider2D.h"
#include "hsCollisionManager.h"
#include "hsTile.h"
#include "hsTilemapRenderer.h"
#include "hsRigidbody.h"

namespace hs
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
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
		// main camera end

		// Player
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);

		mPlayer->AddComponent<Rigidbody>();
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		//CircleCollider2D* collider = mPlayer->AddComponent<CircleCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0));

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(350.0f, 300.0f));
		// Player END

		///CAT
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		Animator* catAnimator = cat->AddComponent<Animator>();

		//BoxCollider2D* boxCatCollider = cat->AddComponent<BoxCollider2D>();
		CircleCollider2D* boxCatCollider = cat->AddComponent<CircleCollider2D>();
		boxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));

		catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);
		catAnimator->PlayAnimation(L"MushroomIdle", true);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		// CAT END

		// Tile
		Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();

		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
		// Tile END

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
	}
	void PlayScene::OnEnter()
	{
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
	}
	void PlayScene::OnExit()
	{
	}
}