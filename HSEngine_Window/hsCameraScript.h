#pragma once
#include "..\\HSEngine_SOURCE\\hsScript.h"
#include "..\\HSEngine_SOURCE\\hsTransform.h"

namespace hs
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}