#pragma once
#include "hsComponent.h"

namespace hs
{
	using namespace hs::math;
	class Camera : public Component
	{
	public:
		// 카메라의 위치를 기준으로 상대 위치를 계산한다
		Vector2 CaluatePosition(Vector2 pos) const { return pos - mDistance; };

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		//std::vector<GameObject*> mGameObjects;
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}