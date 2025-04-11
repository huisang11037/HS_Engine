#include "hsTime.h"

namespace hs {
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	double Time::deltaTime = 0.0f;

	void Time::Initialize()
	{
		// CPU의 고유 진동수를 가져온다
		QueryPerformanceFrequency(&cpuFrequency);

		// 프로그램이 시작됐을 때의 진동수를 가져온다
		QueryPerformanceCounter(&prevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&currentFrequency);

		// "진동수의 차이 / cpu 고유 진동수" 를 통해서 실제 시간이 몇 초 지났는지 파악한다
		double differentFrequency = static_cast<double>(currentFrequency.QuadPart - prevFrequency.QuadPart);
		deltaTime = differentFrequency / static_cast<double>(cpuFrequency.QuadPart);

		prevFrequency.QuadPart = currentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += deltaTime;
		float fps = 1.0f / deltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}