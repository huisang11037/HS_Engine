#include "hsInput.h"

namespace hs {
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[static_cast<size_t>(eKeyCode::END)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};

	void Input::Initialize()
	{
		mKeys.resize(static_cast<size_t>(eKeyCode::END));
		for (size_t i = 0; i < static_cast<size_t>(eKeyCode::END); ++i)
		{
			mKeys[i].keyCode = static_cast<eKeyCode>(i);
			mKeys[i].state = eKeyState::KEY_NONE;
			mKeys[i].isPressed = false;
		}
	}
	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); ++i)
		{
			// 키가 눌렸을 때
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].isPressed == false) mKeys[i].state = eKeyState::KEY_DOWN;
				else mKeys[i].state = eKeyState::KEY_PRESSED;
				mKeys[i].isPressed = true;
			}
			// 키가 눌리지 않았을 때
			else
			{
				// 이전 프레임에 눌러져 있었으면 UP, 아니면 NONE
				if (mKeys[i].isPressed == true) mKeys[i].state = eKeyState::KEY_UP;
				else mKeys[i].state = eKeyState::KEY_NONE;
				mKeys[i].isPressed = false;
			}
		}
	}
}