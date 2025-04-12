#pragma once
#include "hsEntity.h"
#include "hsGameObject.h"

namespace hs
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject) { mGameObjects.push_back(gameObject); }

	private:
		std::vector<GameObject*> mGameObjects;
	};
}
