#pragma once
#include "hsEntity.h"

namespace hs
{
	class Resource abstract : public Entity // 추상 클래스. 반드시 상속받아서 사용해야 한다.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		// 각 자식 클래스마다 Load의 구현이 다르기 때문에 순수가상함수로 선언
		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}