#pragma once
#include "hsComponent.h"
#include "hsAnimation.h"

namespace hs
{
	/**
	* @brief 애니메이션을 관리하는 컴포넌트입니다.
	* @details 애니메이션 생성, 재생, 이벤트를 관리합니다.
	*/
	class Animator : public Component
	{
	public:
		/**
		* @brief 애니메이션 이벤트를 관리하는 구조체입니다.
		* @details 연산자 오버로딩을 통해 std::function<void()>를 사용하여 이벤트를 등록하고 호출할 수 있습니다.
		*/
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};
		/**
		* @brief 애니메이션 이벤트의 시점을 정의하는 구조체입니다.
		*/
		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		/**
		* @brief 애니메이션을 생성하는 함수입니다.
		* @param name 애니메이션의 이름입니다.
		* @param spriteSheet 애니메이션에 사용할 스프라이트 시트입니다.
		* @param leftTop 이미지의 왼쪽 위 좌표입니다.
		* @param tileSize 이미지의 크기입니다.
		* @param offset 이미지의 오프셋입니다.
		* @param spriteLength 애니메이션 스프라이트를 해당 인자만큼 잘라서 사용합니다.
		* @param duration 애니메이션의 지속 시간입니다.
		*/
		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 tileSize
			, Vector2 offset
			, UINT spriteLength
			, float duration);
		/**
		* @brief 애니메이션을 폴더 기반으로 생성하는 함수입니다.
		* @param name 애니메이션의 이름입니다.
		* @param path 애니메이션의 폴더 경로입니다.
		* @param offset 이미지의 오프셋입니다.
		* @param duration 애니메이션의 지속 시간입니다.
		*/
		void CreateAnimationByFolder(const std::wstring& name
			, const std::wstring& path
			, Vector2 offset, float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool bLoop = false);

		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsComplete() { return mActiveAnimation->IsComplete(); }

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		std::map<std::wstring, Events*> mEvents;
	};
}