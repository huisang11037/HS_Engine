#pragma once
#pragma once
#include "..\\HSEngine_SOURCE\hsResources.h"
#include "..\\HSEngine_SOURCE\\hsTexture.h"


namespace hs
{
	/**
	* @brief ���ҽ��� �̸� �ҷ����� �Լ��Դϴ�. ���ο� ���ҽ��� �߰��� ������ �̰��� �߰��մϴ�.
	*/
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphcis::Texture>(L"Player", L"..\\Resources\\Player.bmp");
	}
}