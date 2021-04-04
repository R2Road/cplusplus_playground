#include "r2_RootScene.h"

#include <conio.h>
#include <iostream>
#include <sstream>

#include "r2_Director.h"
#include "r2_RandomTestScene.h"

#include "filesystem_test.h"
#include "shared_pointer_test.h"
#include "variadic_template_test.h"
#include "template_meta_programming_test.h"
#include "optional_test.h"
#include "variant_test.h"
#include "tuple_test.h"
#include "structured_binding_test.h"
#include "const_pointer_test.h"
#include "assert_test.h"
#include "string_view_test.h"


std::string MakeMenuString()
{
	std::stringstream ss;
	ss << "+ Menu" << std::endl;
	ss << "1 : " << filesystem_test::CurrentDirectory::GetInstance().GetTitle() << std::endl;
	ss << "2 : " << "Random" << std::endl;
	ss << "3 : " << shared_pointer_test::SharedPtr::GetInstance().GetTitle() << std::endl;
	ss << "4 : " << variadic_template_test::PrintValues::GetInstance().GetTitle() << std::endl;
	ss << "5 : " << variadic_template_test::SumValues::GetInstance().GetTitle() << std::endl;
	ss << "6 : " << variadic_template_test::SubtractValues::GetInstance().GetTitle() << std::endl;
	ss << "7 : " << template_meta_programming_test::CalculateFactorial::GetInstance().GetTitle() << std::endl;
	ss << "8 : " << template_meta_programming_test::Integer2String::GetInstance().GetTitle() << std::endl;
	ss << "9 : " << template_meta_programming_test::CalculatePlaceValue::GetInstance().GetTitle() << std::endl;
	ss << "Q : " << template_meta_programming_test::Integer2String_II::GetInstance().GetTitle() << std::endl;
	ss << "W : " << optional_test::Basic::GetInstance().GetTitle() << std::endl;
	ss << "E : " << variant_test::Basic::GetInstance().GetTitle() << std::endl;
	ss << "R : " << variadic_template_test::SizeOfArgs::GetInstance().GetTitle() << std::endl;
	ss << "T : " << tuple_test::Basic::GetInstance().GetTitle() << std::endl;
	ss << "Y : " << structured_binding_test::Basic::GetInstance().GetTitle() << std::endl;
	ss << "I : " << const_pointer_test::Basic::GetInstance().GetTitle() << std::endl;
	ss << "O : " << assert_test::Basic::GetInstance().GetTitle() << std::endl;
	ss << "P : " << template_meta_programming_test::MultiTypePackage::GetInstance().GetTitle() << std::endl;
	ss << "A : " << stringview_test::Basic::GetInstance().GetTitle() << std::endl;

	ss << std::endl << "Press Number" << std::endl;

	return std::string( ss.str() );
}

namespace r2
{
	RootScene::RootScene( Director& director ) : iScene( director ) {}

	SceneUp RootScene::Create( Director& director )
	{
		return SceneUp( new ( std::nothrow ) MyT( director ) );
	}

	void RootScene::ShowTitle() const
	{
		std::cout << "# Root #" << std::endl << std::endl;
	}
	void RootScene::ShowMenu() const
	{
		static std::string menu_string( std::move( MakeMenuString() ) );
		std::cout << menu_string;
	}

	iScene::eResult RootScene::Do( const int key_code )
	{
		switch( key_code )
		{
		case '1':
			filesystem_test::CurrentDirectory::GetInstance().Do();
			break;

		case '2':
			mDirector.Setup( r2::RandomTestScene::Create( mDirector ) );
			return iScene::eResult::ChangeScene;

		case '3':
			shared_pointer_test::SharedPtr::GetInstance().Do();
			break;
		case '4':
			variadic_template_test::PrintValues::GetInstance().Do();
			break;
		case '5':
			variadic_template_test::SumValues::GetInstance().Do();
			break;
		case '6':
			variadic_template_test::SubtractValues::GetInstance().Do();
			break;
		case '7':
			template_meta_programming_test::CalculateFactorial::GetInstance().Do();
			break;
		case '8':
			template_meta_programming_test::Integer2String::GetInstance().Do();
			break;
		case '9':
			template_meta_programming_test::CalculatePlaceValue::GetInstance().Do();
			break;
		case 'q':
			template_meta_programming_test::Integer2String_II::GetInstance().Do();
			break;
		case 'w':
			optional_test::Basic::GetInstance().Do();
			break;
		case 'e':
			variant_test::Basic::GetInstance().Do();
			break;
		case 'r':
			variadic_template_test::SizeOfArgs::GetInstance().Do();
			break;
		case 't':
			tuple_test::Basic::GetInstance().Do();
			break;
		case 'y':
			structured_binding_test::Basic::GetInstance().Do();
			break;
		case 'i':
			const_pointer_test::Basic::GetInstance().Do();
			break;
		case 'o':
			assert_test::Basic::GetInstance().Do();
			break;
		case 'p':
			template_meta_programming_test::MultiTypePackage::GetInstance().Do();
			break;

		case 'a':
			stringview_test::Basic::GetInstance().Do();
			break;

		case 27: // ESC
			return iScene::eResult::Exit;
		}

		return iScene::eResult::RunTest;
	}
}