#pragma once
#include "hsEntity.h"

namespace hs
{
	class GameObject; // 전방 선언을 통해 순환 참조를 방지
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; };
		GameObject* GetOwner() { return mOwner; }
	private:
		GameObject* mOwner;
	};
}