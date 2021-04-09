#include "new_test.h"

#include <iostream>
#include <new>

#include "r2_eTestResult.h"

namespace new_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "New : Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== New ==" << std::endl << std::endl;

			{
				int* i = new int( 1 );

				std::cout << "\t" << "+ int* i = new int( 1 );" <<  std::endl;
				std::cout << "\t\t" << "- " << *i << std::endl;

				delete i;
				std::cout << "\t" << "+ delete i;" << std::endl;
			}

			std::cout << std::endl << std::endl;

			{
				int* i = new ( std::nothrow ) int( 2 );

				std::cout << "\t" << "+ int* i = new ( std::nothrow ) int( 2 );" << std::endl;
				std::cout << "\t\t" << "- " << *i << std::endl;

				delete i;
				std::cout << "\t" << "+ delete i;" << std::endl;
			}

			std::cout << std::endl << std::endl;

			{
				char* str = new char[7];

				std::cout << "\t" << "+ char* str = new char[7];" << std::endl;
				std::cout << "\t\t" << "- " << str << std::endl;

				delete[] str;
				std::cout << "\t" << "+ delete[] str;" << std::endl;
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc PlacementNew::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Placement New : Basic";
		};
	}
	const r2::iNode::DoFunc PlacementNew::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Placement New ==" << std::endl << std::endl;

			{
				int i = 123;
				int* ip = new (&i) int;

				std::cout << "\t" << "+ int i = 123;" << std::endl;
				std::cout << "\t" << "+ int* ip = new (&i) int;" << std::endl;
				std::cout << "\t\t" << "- Print ip : " << *ip << std::endl;
			}

			std::cout << std::endl << std::endl << std::endl;

			{
				int i = 65;
				std::cout << "\t" << "+ int i = 65;" << std::endl;
				std::cout << "\t\t" << "- Print i : " << i << std::endl;

				std::cout << std::endl;

				char* cp = new ( &i ) char;
				std::cout << "\t" << "+ char* cp = new ( &i ) char;" << std::endl;
				std::cout << "\t\t" << "- Print cp : " << *cp << std::endl;
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}
}