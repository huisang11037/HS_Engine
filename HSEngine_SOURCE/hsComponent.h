#pragma once
#include "hsEntity.h"

namespace hs
{
	using namespace enums;

	class GameObject; // 전방 선언을 통해 순환 참조를 방지
	/**
	* @brief 컴포넌트는 게임 오브젝트에 부착되어 기능을 추가합니다.
	* @details 유니티의 그 컴포넌트입니다.
	*/
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mOwner = owner; };
		GameObject* GetOwner() { return mOwner; }
		enums::eComponentType GetType() const { return mType; }

	private:
		GameObject* mOwner;
		enums::eComponentType mType;
	};
}