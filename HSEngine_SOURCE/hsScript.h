#pragma once
#include "hsComponent.h"


namespace hs
{
	/**
	* @brief ��� ��ũ��Ʈ�� �⺻ Ŭ������ ������Ʈ�Դϴ�.
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

	private:

	};
}