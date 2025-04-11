#pragma once
#include "CommonInclude.h"

namespace hs
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc) const;

		void SetPosition(float x, float y) { mX = x; mY = y; };
		float GetPositionX() const { return mX; };
		float GetPositionY() const { return mY; };

	private:
		float mX;
		float mY;
	};
}

