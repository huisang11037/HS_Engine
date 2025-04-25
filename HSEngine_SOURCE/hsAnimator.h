#pragma once
#include "hsComponent.h"
#include "hsAnimation.h"

namespace hs
{
	/**
	* @brief �ִϸ��̼��� �����ϴ� ������Ʈ�Դϴ�.
	* @details �ִϸ��̼� ����, ���, �̺�Ʈ�� �����մϴ�.
	*/
	class Animator : public Component
	{
	public:
		/**
		* @brief �ִϸ��̼� �̺�Ʈ�� �����ϴ� ����ü�Դϴ�.
		* @details ������ �����ε��� ���� std::function<void()>�� ����Ͽ� �̺�Ʈ�� ����ϰ� ȣ���� �� �ֽ��ϴ�.
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
		* @brief �ִϸ��̼� �̺�Ʈ�� ������ �����ϴ� ����ü�Դϴ�.
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
		* @brief �ִϸ��̼��� �����ϴ� �Լ��Դϴ�.
		* @param name �ִϸ��̼��� �̸��Դϴ�.
		* @param spriteSheet �ִϸ��̼ǿ� ����� ��������Ʈ ��Ʈ�Դϴ�.
		* @param leftTop �̹����� ���� �� ��ǥ�Դϴ�.
		* @param tileSize �̹����� ũ���Դϴ�.
		* @param offset �̹����� �������Դϴ�.
		* @param spriteLength �ִϸ��̼� ��������Ʈ�� �ش� ���ڸ�ŭ �߶� ����մϴ�.
		* @param duration �ִϸ��̼��� ���� �ð��Դϴ�.
		*/
		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 tileSize
			, Vector2 offset
			, UINT spriteLength
			, float duration);
		/**
		* @brief �ִϸ��̼��� ���� ������� �����ϴ� �Լ��Դϴ�.
		* @param name �ִϸ��̼��� �̸��Դϴ�.
		* @param path �ִϸ��̼��� ���� ����Դϴ�.
		* @param offset �̹����� �������Դϴ�.
		* @param duration �ִϸ��̼��� ���� �ð��Դϴ�.
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