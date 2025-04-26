#include "hsApplication.h"
#include "hsInput.h"
#include "hsTime.h"
#include "hsSceneManager.h"
#include "hsResources.h"
#include "hsCollisionManager.h"
#include "hsUIManager.h"

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
		adjustWindowRect(hwnd, width, height);
		createBackBuffer(width, height);

		initializeETC();

		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}
	void Application::Update()
	{
		Input::Update();
		Time::Update();
		CollisionManager::Update();
		UIManager::Update();
		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHDC);
		CollisionManager::Render(mBackHDC);
		SceneManager::Render(mBackHDC);
		UIManager::Render(mBackHDC);

		// 백버퍼를 화면에 그린다
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Release()
	{
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();
	}
	void Application::clearRenderTarget() const
	{
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, grayBrush);

		// 뒷 배경을 지운다. 원래 크기보다 살짝 크게 해줘야 외곽선이 안보인다.
		Rectangle(mBackHDC, -1, -1, mWidth + 1, mHeight + 1);

		(HBRUSH)SelectObject(mBackHDC, oldBrush);
		DeleteObject(grayBrush);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}
	void Application::createBackBuffer(UINT width, UINT height)
	{
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void Application::initializeETC()
	{
		Input::Initialize();
		Time::Initialize();
	}
}
