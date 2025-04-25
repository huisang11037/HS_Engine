#include "hsFloorScript.h"
#include "hsCatScript.h"
#include "hsInput.h"
#include "hsTransform.h"
#include "hsTime.h"
#include "hsGameObject.h"
#include "hsAnimator.h"
#include "hsObject.h"
#include "hsRigidbody.h"
#include "hsCollider.h"

namespace hs
{
	FloorScript::FloorScript()
	{
	}
	FloorScript::~FloorScript()
	{
	}
	void FloorScript::Initialize()
	{
	}
	void FloorScript::Update()
	{
	}
	void FloorScript::LateUpdate()
	{
	}
	void FloorScript::Render(HDC hdc)
	{
	}
	void FloorScript::OnCollisionEnter(Collider* other)
	{
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
		Transform* floorTr = this->GetOwner()->GetComponent<Transform>();
		Collider* playerCol = other->GetOwner()->GetComponent<Collider>();
		Collider* floorCol = this->GetOwner()->GetComponent<Collider>();

		Vector2 playerPos = playerTr->GetPosition();
		float floorTopY = floorTr->GetPosition().y - floorCol->GetSize().y * 0.5f;
		playerPos.y = floorTopY - playerCol->GetSize().y * 0.5f;

		playerTr->SetPosition(playerPos);
		playerRb->SetGround(true);
	}
	void FloorScript::OnCollisionStay(Collider* other)
	{
	}
	void FloorScript::OnCollisionExit(Collider* other)
	{
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		playerRb->SetGround(false);
	}
}