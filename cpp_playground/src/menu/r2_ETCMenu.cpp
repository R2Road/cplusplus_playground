#include "pch.h"
#include "r2_ETCMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/class_test.h"
#include "test_cpp/etc_0_test.h"

namespace r2
{
	MenuUp ETCMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', etc_test::XOR_Swap::GetInstance() );
			ret->AddChild( '2', etc_test::InitArray::GetInstance() );
			ret->AddChild( '3', etc_test::FillSequenceNumber::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', class_test::Braces::GetInstance() );
			ret->AddChild( 'w', class_test::PrintName::GetInstance() );


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