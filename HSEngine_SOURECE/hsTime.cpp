#include "hsTime.h"

namespace hs {
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	double Time::deltaTime = 0.0f;

	void Time::Initialize()
	{
		// CPU�� ���� �������� �����´�
		QueryPerformanceFrequency(&cpuFrequency);

		// ���α׷��� ���۵��� ���� �������� �����´�
		QueryPerformanceCounter(&prevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&currentFrequency);

		// "�������� ���� / cpu ���� ������" �� ���ؼ� ���� �ð��� �� �� �������� �ľ��Ѵ�
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