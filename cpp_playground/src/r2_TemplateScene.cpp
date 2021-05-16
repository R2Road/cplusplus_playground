#include "pch.h"
#include "r2_TemplateScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "r2_VariadicTemplateScene.h"
#include "r2_TemplateMetaProgrammingScene.h"
#include "r2_TemplatePracticeScene.h"

namespace r2
{
	SceneUp TemplateScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild(
				'1'
				, []()->const char* { return r2::VariadicTemplateScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::VariadicTemplateScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'2'
				, []()->const char* { return r2::TemplateMetaProgrammingScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplateMetaProgrammingScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'3'
				, []()->const char* { return r2::TemplatePracticeScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplatePracticeScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();


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