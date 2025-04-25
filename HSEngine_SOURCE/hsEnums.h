#pragma once

namespace hs::enums
{
	/**
	* @brief ������Ʈ�� ������ �����մϴ�. �� ������Ʈ�� ���� �� �����ؾ� �մϴ�.
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
	* @brief ���̾��� ������ �����մϴ�. �� ���̾ ���� �� �����ؾ� �մϴ�.
	* @details None���� ���ʴ�� ȭ�鿡 �׷����ϴ�. ��, ���ڰ� ���� enum�� �ٸ� ���̾ ���� �������ϴ�. MAX�� 16�Դϴ�.
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
	* @brief ���ҽ��� ������ �����մϴ�. �� ���ҽ��� ���� �� �����ؾ� �մϴ�.
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
	* @brief �浹ü�� ������ �����մϴ�. �� �浹ü�� ���� �� �����ؾ� �մϴ�.
	*/
	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};
}