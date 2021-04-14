#include "pch.h"
#include "r2_RootScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_PointerTestScene.h"
#include "r2_RandomTestScene.h"
#include "r2_TemplateScene.h"
#include "r2_VariadicTemplateScene.h"
#include "r2_AlignOfScene.h"
#include "r2_AlignScene.h"

#include "filesystem_test.h"
#include "shared_pointer_test.h"
#include "optional_test.h"
#include "variant_test.h"
#include "tuple_test.h"
#include "structured_binding_test.h"
#include "pointer_test.h"
#include "assert_test.h"
#include "string_view_test.h"
#include "enum_test.h"
#include "new_test.h"
#include "korean_test.h"

namespace r2
{
	SceneUp RootScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Root" ) );

		{
			ret->AddChild( '1', filesystem_test::CurrentDirectory::GetInstance() );

			ret->AddChild(
				'2'
				, []()->const char* { return "Pointer"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::PointerTestScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'3'
				, []()->const char* { return "Random"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RandomTestScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'4'
				, []()->const char* { return "Variadic Template"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::VariadicTemplateScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'5'
				, []()->const char* { return "Template"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplateScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'6'
				, []()->const char* { return "Align Of"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::AlignOfScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'7'
				, []()->const char* { return "Align"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::AlignScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild( '8', shared_pointer_test::SharedPtr::GetInstance() );

			ret->AddChild( 'w', optional_test::Basic::GetInstance() );
			ret->AddChild( 'e', variant_test::Basic::GetInstance() );
			ret->AddChild( 't', tuple_test::Basic::GetInstance() );
			ret->AddChild( 'y', structured_binding_test::Basic::GetInstance() );			
			ret->AddChild( 'o', assert_test::Basic::GetInstance() );

			ret->AddChild( 'a', stringview_test::Basic::GetInstance() );
			ret->AddChild( 's', enum_test::Basic::GetInstance() );
			ret->AddChild( 'd', enum_test::Convert::GetInstance() );
			ret->AddChild( 'f', new_test::Basic::GetInstance() );
			ret->AddChild( 'g', new_test::PlacementNew::GetInstance() );

			ret->AddChild( 'b', korean_test::Basic::GetInstance() );

			ret->AddChild(
				27
				, []()->const char* { return "\nESC : Exit"; }
				, []()->const eTestResult { return eTestResult::Exit; }
			);
		}

		return ret;
	}
}