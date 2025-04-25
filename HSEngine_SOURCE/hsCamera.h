#pragma once
#include "hsComponent.h"

namespace hs
{
	using namespace hs::math;
	/**
	* @brief 카메라를 기준으로 게임 오브젝트의 위치를 계산하는 컴포넌트입니다.
	*/
	class Camera : public Component
	{
	public:
		Vector2 CaluatePosition(Vector2 pos) const { return pos - mDistance; };
		Vector2 CaluateTilePosition(Vector2 pos) const { return pos + mDistance; };

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; };

	private:
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}