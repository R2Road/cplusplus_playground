#include "pch.h"
#include "time_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()

#include "r2_eTestResult.h"

namespace time_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Time";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			time_t current_time = 0;
			time_t last_time = 0;

			bool process = true;
			while( process )
			{
				time( &current_time );  /* get current time; same as: timer = time(NULL)  */
				if( last_time != current_time )
				{
					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
					std::cout << "[ESC] Exit" << r2::linefeed;
					std::cout << r2::split;
					std::cout << "\t" << "time( &current_time );" << r2::linefeed;
					std::cout << "\t\t" << current_time << r2::linefeed;
					std::cout << r2::split;

					last_time = current_time;
				}

				if( _kbhit() )
				{
					switch( _getch() )
					{
					case 27: // ESC
						process = false;
						break;
					}
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc Clock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Clock";
		};
	}
	r2::iTest::DoFunc Clock::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			clock_t current_clock = 0;
			clock_t current_sec = 0;

			bool process = true;
			while( process )
			{
				current_clock = clock();
				current_sec = current_clock / CLOCKS_PER_SEC;

				system( "cls" );

				std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
				std::cout << "[ESC] Exit" << r2::linefeed;
				std::cout << r2::split;
				std::cout << "\t" << "current_clock = clock();" << r2::linefeed;
				std::cout << "\t\t" << "clock : " << current_clock << "\t\t" "sec : " << current_sec << r2::linefeed;
				std::cout << r2::split;

				if( _kbhit() )
				{
					switch( _getch() )
					{
					case 27: // ESC
						process = false;
						break;
					}
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}