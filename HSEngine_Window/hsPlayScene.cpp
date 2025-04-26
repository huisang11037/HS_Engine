#include "hsPlayScene.h"
#include "hsGameObject.h"
#include "hsPlayer.h"
#include "hsUIManager.h"
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
#include "hsFloor.h"
#include "hsFloorScript.h"

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
		//object::DontDestroyOnLoad(mPlayer);

		mPlayer->AddComponent<Rigidbody>();
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		//BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		CircleCollider2D* collider = mPlayer->AddComponent<CircleCollider2D>();
		collider->SetSize(Vector2(100.0f, 100.0f));

		//graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		//Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		//playerAnimator->CreateAnimation(L"Idle", playerTex
		//	, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		//playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
		//	, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		//playerAnimator->PlayAnimation(L"Idle", false);

		//playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);


		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(600.0f, 300.0f));
		// Player END

		Floor* floor = object::Instantiate<Floor>(eLayerType::Floor, Vector2(600.0f, 600.0f));
		floor->SetName(L"Floor");
		BoxCollider2D* floorCol = floor->AddComponent<BoxCollider2D>();
		floorCol->SetSize(Vector2(300.0f, 50.0f));
		floor->AddComponent<FloorScript>();

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
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);

		UIManager::Push(eUIType::Button);
	}
	void PlayScene::OnExit()
	{
		UIManager::Pop(eUIType::Button);
	}
}