#pragma once
#include "CommonInclude.h"
#include "hsGameObject.h"

namespace hs {
	/**
	* @brief main에서 호출되는 가장 상위의 클래스입니다.
	* @details 윈도우 핸들, 크기, 백 버퍼를 관리합니다.
	* @details 다른 오브젝트들을 업데이트하고 렌더링합니다.
	*/
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void Destroy();
		void Release();

		HWND GetHwnd() const { return mHwnd; }
		HDC GetHdc() const { return mHdc; }
		UINT GetWidth() const { return mWidth; }
		UINT GetHeight() const { return mHeight; }

	private:
		void clearRenderTarget() const;
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBackBuffer(UINT width, UINT height);
		void initializeETC();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHDC;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
	};
}


