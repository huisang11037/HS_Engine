#pragma once
#include "hsEntity.h"

namespace hs
{
	class Resource abstract : public Entity // �߻� Ŭ����. �ݵ�� ��ӹ޾Ƽ� ����ؾ� �Ѵ�.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		// �� �ڽ� Ŭ�������� Load�� ������ �ٸ��� ������ ���������Լ��� ����
		virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ�

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}