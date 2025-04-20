#pragma once
#include "..\\HSEngine_SOURCE\\hsScript.h"


namespace hs
{
	class PlayerScript : public Script
	{
	public:
		enum class ePlayerState
		{
			SitDown,
			Move,
			Sleep,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void sitDown();
		void move();

	private:
		ePlayerState mState;
		class Animator* mAnimator;
	};
}