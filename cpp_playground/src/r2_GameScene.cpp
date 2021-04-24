#include "pch.h"
#include "r2_GameScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "r2_game_PathFinder.h"

namespace r2
{
	SceneUp GameScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', r2_game::PathFinder::GetInstance() );
			
			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RootScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}