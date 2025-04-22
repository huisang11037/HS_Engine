#pragma once
#include "hsComponent.h"

namespace hs
{
	using namespace hs::math;
	class Camera : public Component
	{
	public:
		// ī�޶��� ��ġ�� �������� ��� ��ġ�� ����Ѵ�
		Vector2 CaluatePosition(Vector2 pos) const { return pos - mDistance; };

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; };

	private:
		//std::vector<GameObject*> mGameObjects;
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}