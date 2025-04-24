#pragma once
#include "CommonInclude.h"

namespace hs {
	/**
	* @brief 시간 관련 기능을 정의합니다.
	*/
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
