#pragma once
#pragma once
#include "..\\HSEngine_SOURECE\hsResources.h"
#include "..\\HSEngine_SOURECE\\hsTexture.h"

namespace hs
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
	}
}