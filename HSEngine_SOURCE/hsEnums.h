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
		//character
		Animal,
		Player,
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

}