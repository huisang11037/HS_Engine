#include "hsInput.h"

namespace hs {
	std::vector<Input::Key> Input::keys = {};

	int ASCII[static_cast<size_t>(eKeyCode::END)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};

	void Input::Initialize()
	{
		createKeys();
	}
	void Input::Update()
	{
		updateKeys();
	}

	void Input::createKeys()
	{
		keys.resize(static_cast<size_t>(eKeyCode::END));
		for (size_t i = 0; i < static_cast<size_t>(eKeyCode::END); ++i)
		{
			keys[i].keyCode = static_cast<eKeyCode>(i);
			keys[i].state = eKeyState::KEY_NONE;
			keys[i].isPressed = false;
		}
	}

	void Input::updateKeys()
	{
		for (size_t i = 0; i < keys.size(); ++i)
		{
			// Ű�� ������ ��
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// ó�� ������ �Ŷ�� DOWN, �̹� �����־��ٸ� PRESSED
				if (keys[i].isPressed == false) keys[i].state = eKeyState::KEY_DOWN;
				else keys[i].state = eKeyState::KEY_PRESSED;
				keys[i].isPressed = true;
			}
			// Ű�� ������ �ʾ��� ��
			else
			{
				// ���� �����ӿ� ������ �־����� UP, �ƴϸ� NONE
				if (keys[i].isPressed == true) keys[i].state = eKeyState::KEY_UP;
				else keys[i].state = eKeyState::KEY_NONE;
				keys[i].isPressed = false;
			}
		}
	}
}