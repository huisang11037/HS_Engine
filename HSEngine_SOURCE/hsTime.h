#pragma once
#include "CommonInclude.h"

namespace hs {
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static double DeltaTime() { return deltaTime; }

	private:
		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER currentFrequency;
		static double deltaTime;
	};
}
