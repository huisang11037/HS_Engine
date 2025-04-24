#pragma once
#include "hsEntity.h"

namespace hs
{
	using namespace enums;

	class GameObject; // ���� ������ ���� ��ȯ ������ ����
	/**
	* @brief ������Ʈ�� ���� ������Ʈ�� �����Ǿ� ����� �߰��մϴ�.
	* @details ����Ƽ�� �� ������Ʈ�Դϴ�.
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