#include "hsTransform.h"

namespace hs
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mPosition(Vector2::Zero)
		, mScale(Vector2::One)
		, mRotation(0.0f)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
		// 빨간 사각형 그리기
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		Rectangle(hdc, mPosition.x - 5, mPosition.y - 5, mPosition.x + 5, mPosition.y + 5);

		SelectObject(hdc, oldPen);
		DeleteObject(redPen);
	}
}