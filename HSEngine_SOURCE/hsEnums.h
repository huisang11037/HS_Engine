#pragma once

namespace hs::enums
{
	/**
	* @brief 컴포넌트의 종류를 정의합니다. 새 컴포넌트를 만들 때 수정해야 합니다.
	*/
	enum class eComponentType
	{
		Transform,
		Colider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};
	/**
	* @brief 레이어의 종류를 정의합니다. 새 레이어를 만들 때 수정해야 합니다.
	* @details None부터 차례대로 화면에 그려집니다. 즉, 숫자가 작은 enum이 다른 레이어에 의해 가려집니다. MAX는 16입니다.
	*/
	enum class eLayerType
	{
		None,
		BackGround,
		//Tree
		Tile,
		//character
		Animal,
		Player,
		Particle,
		Max = 16,
	};
	/**
	* @brief 리소스의 종류를 정의합니다. 새 리소스를 만들 때 수정해야 합니다.
	*/
	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
	/**
	* @brief 충돌체의 종류를 정의합니다. 새 충돌체를 만들 때 수정해야 합니다.
	*/
	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};
}