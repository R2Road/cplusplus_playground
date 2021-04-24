#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class TemplatePracticeScene
	{
	private:
		TemplatePracticeScene() = delete;

	public:
		static const char* GetTitle() { return "Template Practice"; }
		static SceneUp Create( Director& director );
	};
}