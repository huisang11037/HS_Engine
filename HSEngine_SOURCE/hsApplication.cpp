#include "hsApplication.h"
#include "hsInput.h"
#include "hsTime.h"
#include "hsSceneManager.h"

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

		SceneManager::Initialize();

		initializeETC();
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
		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHDC);
		SceneManager::Render(mBackHDC);

		// ����۸� ȭ�鿡 �׸���
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
	void Application::clearRenderTarget()
	{
		// �� ����� �����. ���� ũ�⺸�� ��¦ ũ�� ����� �ܰ����� �Ⱥ��δ�.
		Rectangle(mBackHDC, -1, -1, mWidth + 1, mHeight + 1);
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
		// ������ �ػ󵵿� �´� �����	 ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����ۿ� ���� DC ����
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
