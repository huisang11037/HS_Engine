#pragma once
#include "hsComponent.h"

namespace hs
{
	/**
	* @brief Collider는 물체의 충돌을 생성하는 컴포넌트입니다. 트랜스폼을 중심으로 충돌 범위가 그려집니다.
	*/
	class Collider : public Component
	{
	public:
		Collider(eColliderType type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void SetOffset(Vector2 offset) { mOffset = offset; }
		void SetSize(Vector2 size) { mSize = size; }
		Vector2 GetOffset() const { return mOffset; }
		Vector2 GetSize() const { return mSize; }
		UINT32 GetID() const { return mID; }
		eColliderType GetColliderType() const { return mType; }

	private:
		static UINT CollisionID;

		UINT32 mID;
		Vector2 mOffset;
		Vector2 mSize;

		eColliderType mType;
	};
}