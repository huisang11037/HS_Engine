#pragma once
#pragma once
#include "..\\HSEngine_SOURCE\hsResources.h"
#include "..\\HSEngine_SOURCE\\hsTexture.h"


namespace hs
{
	/**
	* @brief 리소스를 미리 불러오는 함수입니다. 새로운 리소스를 추가할 때마다 이곳에 추가합니다.
	*/
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphcis::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}