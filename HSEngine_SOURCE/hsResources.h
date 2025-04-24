#pragma once
#include "hsResource.h"

namespace hs
{
	/**
	* @brief 리소스를 불러오거나 찾는 함수를 정의합니다.
	*/
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter = mResources.find(key);
			if (iter == mResources.end()) return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			assert(resource == nullptr);

			resource = new T();
			HRESULT hr = resource->Load(path);
			assert(SUCCEEDED(hr));

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

		static void Insert(const std::wstring& key, Resource* resource)
		{
			mResources.insert(std::make_pair(key, resource));
		}
		static void Release()
		{
			for (auto& iter : mResources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}