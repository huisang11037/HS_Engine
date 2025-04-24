#include "hsCollider.h"
#include "hsGameObject.h"
#include "hsScript.h"

namespace hs
{
	UINT Collider::CollisionID = 1;

	Collider::Collider()
		: Component(enums::eComponentType::Colider)
		, mID(CollisionID++)
		, mSize(Vector2::One)
	{

	}
	Collider::~Collider()
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render(HDC hdc)
	{
	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if (script == nullptr) return;
		script->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if (script == nullptr) return;
		script->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		if (script == nullptr) return;
		script->OnCollisionExit(other);
	}
}