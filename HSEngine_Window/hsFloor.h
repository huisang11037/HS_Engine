#pragma once
#include "..\\HSEngine_SOURCE\\hsGameObject.h"

namespace hs
{
	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}