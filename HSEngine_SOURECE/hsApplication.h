#pragma once
#include "CommonInclude.h"
#include "hsGameObject.h"

namespace hs {
	class Application
	{
	public:
		Application();
		~Application();


		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		hs::GameObject mPlayer;
	};
}


