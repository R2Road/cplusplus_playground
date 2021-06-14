#include "pch.h"
#include "thread_test.h"

#include <conio.h>
#include <thread>

#include "base/r2_eTestResult.h"
#include "renderer/r2_FrameManager.h"

namespace thread_test
{
	void thread_func_1()
	{
		for( auto i = 0; 20 > i; ++i )
		{
			std::cout << "thread_func_1 : " << i << r2::linefeed;
		}
	}

	void thread_func_2()
	{
		for( auto i = 0; 20 > i; ++i )
		{
			std::cout << "thread_func_2 : " << i << r2::linefeed;
		}
	}

	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Thread - Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::thread t1( thread_func_1 );
				std::thread t2( thread_func_2 );

				t1.join();
				t2.join();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}