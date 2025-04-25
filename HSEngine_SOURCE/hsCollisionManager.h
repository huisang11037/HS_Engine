#pragma once
#include "CommonInclude.h"
#include "hsBoxCollider2D.h"
#include "hsCircleCollider2D.h"

namespace hs
{
	using namespace enums;

	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};
	/**
	* @brief 모든 콜라이더를 관리하는 정적 클래스입니다.
	*/
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Clear();

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool IsIntersect(Collider* left, Collider* right);

	private:
		static bool isCircleRectCollision(enums::eColliderType leftType, 
			Vector2* leftPos, Vector2* leftSize, Vector2* rightPos, Vector2* rightSize);

	private:
		static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}