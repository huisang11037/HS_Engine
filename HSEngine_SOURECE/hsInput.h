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

		static bool GetKeyDown(eKeyCode key) { return keys[static_cast<size_t>(key)].state == eKeyState::KEY_DOWN; }
		static bool GetKeyUp(eKeyCode key) { return keys[static_cast<size_t>(key)].state == eKeyState::KEY_UP; }
		static bool GetKey(eKeyCode key) { return keys[static_cast<size_t>(key)].state == eKeyState::KEY_PRESSED; }

	private:
		static std::vector<Key> keys;

		static void createKeys();
		static void updateKeys();
	};
}