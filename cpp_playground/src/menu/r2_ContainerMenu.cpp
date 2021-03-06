#include "pch.h"
#include "r2_ContainerMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/std_array_test.h"
#include "test_cpp/vector_test.h"

namespace r2
{
	MenuUp ContainerMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', std_array_test::Basic::GetInstance() );
			ret->AddChild( '2', std_array_test::Fill::GetInstance() );
			ret->AddChild( '3', vector_test::Basic::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}