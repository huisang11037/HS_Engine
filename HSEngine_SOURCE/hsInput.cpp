#include "hsInput.h"
#include "hsApplication.h"

extern hs::Application application;

namespace hs {
	std::vector<Input::Key> Input::keys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::One;

	int ASCII[static_cast<size_t>(eKeyCode::END)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
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
			keys[i].bPressed = false;
		}
	}
	void Input::updateKeys()
	{
		std::for_each(keys.begin(), keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}
	void Input::updateKey(Input::Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
				updateKeyDown(key);
			else
				updateKeyUp(key);

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}
	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::KEY_PRESSED;
		else
			key.state = eKeyState::KEY_DOWN;

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::KEY_UP;
		else
			key.state = eKeyState::KEY_NONE;

		key.bPressed = false;
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = { };
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		UINT width = application.GetWidth();
		UINT height = application.GetHeight();

		mMousePosition.x = -1.0f;
		mMousePosition.y = -1.0f;

		if (mousePos.x > 0 && mousePos.x < width && mousePos.y > 0 && mousePos.y < height)
		{
			mMousePosition.x = mousePos.x;
			mMousePosition.y = mousePos.y;
		}
	}
	void Input::clearKeys()
	{
		for (Key& key : keys)
		{
			if (key.state == eKeyState::KEY_DOWN || key.state == eKeyState::KEY_PRESSED)
				key.state = eKeyState::KEY_UP;
			else if (key.state == eKeyState::KEY_UP)
				key.state = eKeyState::KEY_NONE;

			key.bPressed = false;
		}
	}
}