#pragma once
#include "..\\HSEngine_SOURCE\\hsScript.h"


namespace hs
{
	class PlayerScript : public Script
	{
	public:
		enum class ePlayerState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();
		void giveWater();

	private:
		ePlayerState mState;
		class Animator* mAnimator;
	};
}