#pragma once
#pragma once
#include "..\\HSEngine_SOURCE\hsResources.h"
#include "..\\HSEngine_SOURCE\\hsTexture.h"

namespace hs
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Map", L"..\\Resources\\CloudOcean.png");
		Resources::Load<graphcis::Texture>(L"PackMan", L"..\\Resources\\Player1.png");
		Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphcis::Texture>(L"Bubble", L"..\\Resources\\Bubble.png");
		Resources::Load<graphcis::Texture>(L"Effect", L"..\\Resources\\ezgif.com-gif-maker.png");
	}
}