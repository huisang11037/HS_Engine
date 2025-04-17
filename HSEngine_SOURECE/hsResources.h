#pragma once
#include "hsResource.h"

namespace hs
{
	// ���ҽ� ���� Ŭ����
	// Load�� ���� key�� path�� map�� �����Ѵ�.
	// Find�� ���� key���� ���� �ս��� path�� ���� �� �ִ�.
	class Resources
	{
	public:
		// ���ҽ��� path�� ��� �޼ҵ�
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter = mResources.find(key);
			if (iter == mResources.end()) return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		// ���ҽ��� �ε��ϴ� �޼ҵ�
		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			// �̹� �ε�� ���ҽ����� Ȯ��
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr) return resource;

			// ���ҽ� �ε�
			resource = new T();
			if (FAILED(resource->Load(path))) assert(false); // ��ΰ� �ùٸ��� ���� ���

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}