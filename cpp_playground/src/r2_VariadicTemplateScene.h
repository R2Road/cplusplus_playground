#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class VariadicTemplateScene
	{
	private:
		VariadicTemplateScene() = delete;

	public:
		static const char* GetTitle() { return "Variadic Template"; }
		static SceneUp Create( Director& director );
	};
}