#pragma once
#include "CommonInclude.h"
#include "hsComponent.h"

namespace hs::object
{
	void Destory(GameObject* gameObject);
}

namespace hs
{
	/**
	* @brief 게임 오브젝트는 씬에 존재하는 모든 오브젝트를 정의합니다.
	*/
	class GameObject
	{
	public:
		friend void object::Destory(GameObject* obj);

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			component->Initialize();
			component->SetOwner(this);

			mComponents[(UINT)component->GetType()] = component;
			return component;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

		eState GetState() const { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool IsActive() const { return mState == eState::Active; }
		bool IsDead() const { return mState == eState::Dead; }

	private:
		void initializeTransform();
		void death() { mState = eState::Dead; }

	private:
		eState mState;
		std::vector<Component*> mComponents;
	};
}

