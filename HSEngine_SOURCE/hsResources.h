#pragma once
#include "hsResource.h"

namespace hs
{
	// 리소스 관리 클래스
	// Load를 통해 key와 path를 map에 저장한다.
	// Find를 통해 key값을 토대로 손쉽게 path를 얻을 수 있다.
	class Resources
	{
	public:
		// 리소스의 path를 얻는 메소드
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter = mResources.find(key);
			if (iter == mResources.end()) return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		// 리소스를 로드하는 메소드
		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			// 이미 로드된 리소스인지 확인
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr) return resource;

			// 리소스 로드
			resource = new T();
			if (FAILED(resource->Load(path))) assert(false); // 경로가 올바르지 않을 경우

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}