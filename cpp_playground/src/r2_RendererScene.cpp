#include "pch.h"
#include "r2_RendererScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "renderer_test.h"

namespace r2
{
	SceneUp RendererScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', renderer_test::FrameBuffer_FillAll::GetInstance() );
			ret->AddChild( '2', renderer_test::FrameBuffer_Fill::GetInstance() );
			ret->AddChild( '3', renderer_test::FrameBuffer_DrawWithPosition::GetInstance() );
			ret->AddChild( '4', renderer_test::FrameBuffer_InitWithChars::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'q', renderer_test::TestRenderer::GetInstance() );


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