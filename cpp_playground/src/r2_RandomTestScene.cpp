#include "r2_RandomTestScene.h"

#include <iostream>
#include <sstream>

#include "r2_Director.h"
#include "r2_Scene.h"
#include "random_test.h"

namespace
{
	std::string MakeMenuString()
	{
		std::stringstream ss;
		ss << "+ Menu" << std::endl;
		ss << "1 : " << random_test::Basic::GetTitle() << std::endl;
		ss << "2 : " << random_test::StatusSaveAndLoad::GetTitle() << std::endl;

		ss << std::endl << "Press Number" << std::endl;

		return std::string( ss.str() );
	}
}

namespace r2
{
	RandomTestScene::RandomTestScene( Director* const director ) : iScene( director ) {}

	SceneUp RandomTestScene::Create( Director* const director )
	{
		return SceneUp( new ( std::nothrow ) MyT( director ) );
	}

	void RandomTestScene::ShowMenu()
	{
		static std::string menu_string( std::move( MakeMenuString() ) );
		std::cout << menu_string;
	}

	bool RandomTestScene::Do( const int key_code )
	{
		switch( key_code )
		{
		case '1':
			random_test::Basic::Do();
			break;
		case '2':
			random_test::StatusSaveAndLoad::Do();
			break;

		case 27: // ESC
			mDirector->Setup( r2::Scene::Create( mDirector ) );
			break;
		}

		return true;
	}
}