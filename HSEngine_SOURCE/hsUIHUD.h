#pragma once
#include "hsUIBase.h"
#include "hsTexture.h"

namespace hs
{
	/**
	* @brief UIHUD 클래스는 게임의 HUD(Head-Up Display)를 나타내는 UI를 구현합니다.
	*/
	class UIHUD : public UIBase
	{
	public:
		UIHUD();
		~UIHUD();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

	private:
		graphics::Texture* mTexture;
	};
}