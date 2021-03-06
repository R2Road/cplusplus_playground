#include "pch.h"
#include "new_test.h"

#include <new>

#include "base/r2_eTestResult.h"

namespace new_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int* i = new int( 1 );

				std::cout << r2::tab << "+ int* i = new int( 1 );" <<  r2::linefeed;
				std::cout << r2::tab2 << "- " << *i << r2::linefeed;

				delete i;
				std::cout << r2::tab << "+ delete i;" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int* i = new ( std::nothrow ) int( 2 );

				std::cout << r2::tab << "+ int* i = new ( std::nothrow ) int( 2 );" << r2::linefeed;
				std::cout << r2::tab2 << "- " << *i << r2::linefeed;

				delete i;
				std::cout << r2::tab << "+ delete i;" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				char* str = new char[7];

				std::cout << r2::tab << "+ char* str = new char[7];" << r2::linefeed;
				std::cout << r2::tab2 << "- " << str << r2::linefeed;

				delete[] str;
				std::cout << r2::tab << "+ delete[] str;" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc PlacementNew::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Placement New";
		};
	}
	r2::iTest::DoFunc PlacementNew::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int i = 123;
				float* fp = new (&i) float;

				std::cout << r2::tab << "+ int i = 123;" << r2::linefeed;
				std::cout << r2::tab << "+ float* fp = new (&i) float;" << r2::linefeed;
				std::cout << r2::tab2 << "- Print fp : " << *fp << r2::linefeed;

				std::cout << r2::linefeed;

				*fp = 3.14f;
				std::cout << r2::tab << "+ *fp = 3.14f;" << r2::linefeed;
				std::cout << r2::tab2 << "- Print fp : " << *fp << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int i = 65;
				std::cout << r2::tab << "+ int i = 65;" << r2::linefeed;
				std::cout << r2::tab2 << "- Print i : " << i << r2::linefeed;

				std::cout << r2::linefeed;

				char* cp = new ( &i ) char;
				std::cout << r2::tab << "+ char* cp = new ( &i ) char;" << r2::linefeed;
				std::cout << r2::tab2 << "- Print cp : " << *cp << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}