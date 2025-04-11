#include "hsApplication.h"
#include "hsInput.h"
#include "hsTime.h"

namespace hs {
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHDC(nullptr)
		, mBackBitmap(nullptr)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼	 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼에 대한 DC 생성
		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);

		Input::Initialize();
		Time::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();
		mPlayer.Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		Rectangle(mBackHDC, 0, 0, mWidth, mHeight);

		Time::Render(mBackHDC);
		mPlayer.Render(mBackHDC);

		// 백버퍼를 화면에 그린다
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
}
