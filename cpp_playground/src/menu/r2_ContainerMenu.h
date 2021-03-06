#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class ContainerMenu
	{
	private:
		ContainerMenu() = delete;

	public:
		static const char* GetTitle() { return "Container"; }
		static MenuUp Create( Director& director );
	};
}