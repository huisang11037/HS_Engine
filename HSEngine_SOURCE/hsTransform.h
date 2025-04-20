#pragma once

#include "hsEntity.h"
#include "hsComponent.h"

namespace hs
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		void SetScale(Vector2 scale) { mScale = scale; }
		void SetRotation(float rotation) { mRotation = rotation; }
		Vector2 GetPosition() const { return mPosition; }
		Vector2 GetScale() const { return mScale; }
		float GetRotation() const { return mRotation; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}