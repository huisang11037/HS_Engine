#pragma once
#include "hsEntity.h"

namespace hs
{
	/**
	* @brief 추상 클래스로서 모든 리소스의 기본 클래스입니다.
	*/
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; 

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}