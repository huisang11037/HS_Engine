#pragma once
#include "hsEntity.h"
#include "hsGameObject.h"
#include "hsLayer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, const eLayerType type);

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}
