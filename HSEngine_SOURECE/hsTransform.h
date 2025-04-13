#pragma once

#include "hsEntity.h"
#include "hsComponent.h"

namespace hs
{
	struct Pos
	{
		int mX;
		int mY;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPos(int x, int y) { mX = x; mY = y; }
		int GetX() const { return mX; }
		int GetY() const { return mY; }

	private:
		int mX;
		int mY;
	};
}