#pragma once
#include "..\\HSEngine_SOURCE\\hsGameObject.h"

namespace hs
{

	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}