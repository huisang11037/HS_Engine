#pragma once
#include "hsComponent.h"

namespace hs
{
	class AudioListener : public Component
	{
	public:
		AudioListener();
		~AudioListener();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}