#pragma once
#include "hsEntity.h"
#include "hsGameObject.h"
#include "hsLayer.h"

namespace hs
{
	/**
	* @brief 씬은 해당 화면을 담당하는 상위 클래스입니다.
	*/
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}
