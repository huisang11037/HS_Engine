#pragma once
#include "..\\HSEngine_SOURECE\hsGameObject.h"

namespace hs
{

	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}