#pragma once
#include "CommonInclude.h"

namespace hs {
	enum class eKeyState
	{
		KEY_NONE,
		KEY_DOWN,
		KEY_PRESSED,
		KEY_UP,
	};

	enum class eKeyCode
	{
		KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P,
		KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L,
		KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, 
		KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN,
		LButton, MButton, RButton,
		END
	};

	class Input
	{
	public:
		struct Key 
		{
			eKeyCode keyCode;
			eKeyState state;
			bool isPressed;
		};

		static void Initialize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode key) { return keys[static_cast<size_t>(key)].state == eKeyState::KEY_DOWN; }
		__forceinline static bool GetKeyUp(eKeyCode key) { return keys[static_cast<size_t>(key)].state == eKeyState::KEY_UP; }
		__forceinline static bool GetKey(eKeyCode key) { return keys[static_cast<size_t>(key)].state == eKeyState::KEY_PRESSED; }
		__forceinline static math::Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);
		static void getMousePositionByWindow();
		static void clearKeys();

	private:
		static std::vector<Key> keys;
		static math::Vector2 mMousePosition;
	};
}