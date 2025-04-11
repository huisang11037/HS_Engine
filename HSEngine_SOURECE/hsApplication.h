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

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHDC;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		hs::GameObject mPlayer;
	};
}


