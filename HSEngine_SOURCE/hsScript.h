#pragma once
#include "hsComponent.h"

namespace hs
{
	/**
	* @brief 모든 스크립트의 기본 클래스인 컴포넌트입니다.
	*/
	class Script : public Component
	{
	public:
		Script();
		~Script();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);
	private:

	};
}