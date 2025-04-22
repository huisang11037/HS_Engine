#pragma once
#include "CommonInclude.h"
#include "hsGameObject.h"

namespace hs {
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

		//std::vector<Scene*> mScenes;
	};
}


