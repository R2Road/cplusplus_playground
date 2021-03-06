#include "pch.h"
#include "r2_TemplatePracticeMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_TemplateMenu.h"

#include "test_cpp/template_practice_part_01_test.h"

namespace r2
{
	MenuUp TemplatePracticeMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', template_practice_part_01_test::BufferWithTemplate::GetInstance() );
			ret->AddChild( '2', template_practice_part_01_test::VaridicMax::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}