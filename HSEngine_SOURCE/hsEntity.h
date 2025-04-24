#pragma once
#include "CommonInclude.h"

using namespace hs::math;

namespace hs
{
	/**
	* @brief 모든 이름이 필요한 것들에 대한 기본 클래스입니다.
	*/
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		const std::wstring& GetName() const { return mName; }

	private:
		std::wstring mName;
	};
}
