#pragma once
#include "hsUIBase.h"
#include "hsTexture.h"

namespace hs
{
	/**
	* @brief UIButton 클래스는 버튼 UI를 구현합니다.
	*/
	class UIButton : public UIBase
	{
	public:
		UIButton();
		~UIButton();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnUpdate() override;
		virtual void OnLateUpdate() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void ButtonClick();

	private:
		graphics::Texture* mTexture;
		Event mOnClick;
	};
}