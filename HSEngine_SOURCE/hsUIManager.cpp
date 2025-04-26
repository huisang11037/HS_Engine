#include "hsUIManager.h"
#include "hsUIHUD.h"
#include "hsUIButton.h"

namespace hs
{
	std::unordered_map<eUIType, UIBase*> UIManager::mUIs = {};
	std::deque<UIBase*> UIManager::mUIBases = {};
	std::queue<eUIType> UIManager::mRequestUiQueue = {};
	UIBase* UIManager::mActiveUI = nullptr;

	void UIManager::Initialize()
	{
		UIHUD* hud = new UIHUD();
		mUIs.insert(std::make_pair(eUIType::HpBar, hud));

		UIButton* button = new UIButton();
		mUIs.insert(std::make_pair(eUIType::Button, button));
	}
	void UIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType, UIBase*>::iterator iter
			= mUIs.find(type);

		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}
	void UIManager::Update()
	{
		std::deque<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.front();
			if (uiBase)
			{
				uiBase->Update();
				uiBases.pop_front();
			}
		}

		if (mRequestUiQueue.size() > 0)
		{
			eUIType requestUI = mRequestUiQueue.front();
			mRequestUiQueue.pop();
			OnLoad(requestUI);
		}
	}
	void UIManager::LateUpdate()
	{
		std::deque<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.front();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop_front();
			}
		}
	}
	void UIManager::Render(HDC hdc)
	{
		std::deque<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.front();
			if (uiBase)
			{
				uiBase->Render(hdc);
				uiBases.pop_front();
			}
		}
	}
	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		if (addUI->IsFullScreen())
		{
			std::deque<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				UIBase* uiBase = uiBases.front();
				uiBases.pop_front();
				if (uiBase)
				{
					uiBase->InActive();
				}
			}
		}

		mUIBases.push_back(addUI);
		mActiveUI = nullptr;
	}
	void UIManager::OnFail()
	{
		mActiveUI = nullptr;
	}
	void UIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void UIManager::Push(eUIType type)
	{
		mRequestUiQueue.push(type);
	}
	void UIManager::Pop(eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		std::stack<UIBase*> tempStack;

		UIBase* uibase = nullptr;
		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.back();
			mUIBases.pop_back();

			if (uibase->GetType() != type)
			{
				tempStack.push(uibase);
				continue;
			}

			if (uibase->IsFullScreen())
			{
				std::deque<UIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					UIBase* uiBase = uiBases.front();
					uiBases.pop_front();
					if (uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			uibase->UIClear();
		}

		while (tempStack.size() > 0)
		{
			uibase = tempStack.top();
			tempStack.pop();
			mUIBases.push_back(uibase);
		}
	}
}