#pragma once

#include <memory>

namespace r2
{
	class Director;

	using SceneUp = std::unique_ptr<class iScene>;

	class iScene
	{
	public:
		enum eResult
		{
			RunTest,
			ChangeScene,
			Exit,
		};

		iScene( Director& director ) : mDirector( director ) {}
		virtual ~iScene() {}

		virtual void ShowTitle() const = 0;
		virtual void ShowMenu() = 0;
		virtual eResult Do( const int key_code ) = 0;

	protected:
		Director& mDirector;
	};
}