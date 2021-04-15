#include "pch.h"
#include "r2_MemoryScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "shared_pointer_test.h"

namespace r2
{
	SceneUp MemoryScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', shared_pointer_test::SharedPtr::GetInstance() );

			ret->AddChild(
				27
				, []()->const char* { return "\nESC : Return To Root"; }
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