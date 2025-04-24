#pragma once
#include "hsEntity.h"
#include "CommonInclude.h"
#include "hsGameObject.h"

namespace hs
{
	/**
	* @brief 레이어는 씬에 종속되어 게임 오브젝트를 관리합니다.
	* @details 하위 레이어일수록 상위 레이어에 의해 가려집니다.
	*/
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

		std::vector<GameObject*> GetGameObjects() const { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
		void deleteGameObjects(std::vector<GameObject*> gameObjs);
		void eraseGameObject();

	private:
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}