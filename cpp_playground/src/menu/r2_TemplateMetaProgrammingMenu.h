#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class TemplateMetaProgrammingMenu
	{
	private:
		TemplateMetaProgrammingMenu() = delete;

	public:
		static const char* GetTitle() { return "Template Meta Programming"; }
		static MenuUp Create( Director& director );
	};
}