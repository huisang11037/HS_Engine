#include "hsCollisionManager.h"
#include "hsScene.h"
#include "hsSceneManager.h"
#include "hsGameObject.h"
#include "hsCollider.h"
#include "hsTransform.h"

namespace hs
{
	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}

	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
	{
	}
	void CollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = SceneManager::GetGameObjects(left);
		const std::vector<GameObject*>& rights = SceneManager::GetGameObjects(right);

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;
				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		if (IsIntersect(left, right))
		{
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}
	bool CollisionManager::IsIntersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}


		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
			|| (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
		{
			return isCircleRectCollision(leftType, &leftPos, &leftSize, &rightPos, &rightSize);
		}

		return false;
	}
	bool CollisionManager::isCircleRectCollision(enums::eColliderType leftType
		, Vector2* leftPos, Vector2* leftSize, Vector2* rightPos, Vector2* rightSize)
	{
		Vector2 *circlePos, *rectPos;
		Vector2 *circleSize, *rectSize;

		if (leftType == enums::eColliderType::Circle2D)
		{
			circlePos = leftPos;
			circleSize = leftSize;
			rectPos = rightPos;
			rectSize = rightSize;
		}
		else
		{
			circlePos = rightPos;
			circleSize = rightSize;
			rectPos = leftPos;
			rectSize = leftSize;
		}

		float radius = circleSize->x * 0.5f;

		float rectHalfW = rectSize->x * 0.5f;
		float rectHalfH = rectSize->y * 0.5f;

		float dx = std::abs(circlePos->x - rectPos->x);
		float dy = std::abs(circlePos->y - rectPos->y);

		if (dx > (rectHalfW + radius)) return false;
		if (dy > (rectHalfH + radius)) return false;

		if (dx <= rectHalfW) return true;
		if (dy <= rectHalfH) return true;

		float cornerDistSq = (dx - rectHalfW) * (dx - rectHalfW) +
			(dy - rectHalfH) * (dy - rectHalfH);

		if (cornerDistSq <= radius * radius)
		{
			return true;
		}
		return false;
	}
}