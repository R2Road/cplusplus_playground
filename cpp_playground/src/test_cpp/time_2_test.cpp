#include "pch.h"
#include "time_2_test.h"

#include <conio.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib") // for timeGetTime()

#include "base/r2_eTestResult.h"

namespace time_test
{
	r2::iTest::TitleFunc WindowTime::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Time";
		};
	}
	r2::iTest::DoFunc WindowTime::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SYSTEMTIME local_time;
			SYSTEMTIME system_time;
			DWORD current_tick = 0;
			DWORD last_tick = 0;

			bool process = true;
			while( process )
			{
				GetLocalTime( &local_time );
				GetSystemTime( &system_time );
				current_tick = GetTickCount();

				if( last_tick + 16 < current_tick ) // 60fps
				{

					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
					std::cout << "[ESC] Exit" << r2::linefeed;

					std::cout << r2::split;

					{
						std::cout << r2::tab << "GetLocalTime( &local_time );" << r2::linefeed;
						std::cout << r2::tab2 << local_time.wYear << local_time.wMonth << local_time.wDay << r2::linefeed;
						std::cout << r2::tab2 << local_time.wDayOfWeek << r2::linefeed;
						std::cout << r2::tab2 << local_time.wHour << local_time.wMinute << local_time.wSecond << r2::linefeed;
						std::cout << r2::tab2 << local_time.wMilliseconds << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::cout << r2::tab << "GetSystemTime( &system_time );" << r2::linefeed;
						std::cout << r2::tab2 << system_time.wYear << system_time.wMonth << system_time.wDay << r2::linefeed;
						std::cout << r2::tab2 << system_time.wDayOfWeek << r2::linefeed;
						std::cout << r2::tab2 << system_time.wHour << system_time.wMinute << system_time.wSecond << r2::linefeed;
						std::cout << r2::tab2 << system_time.wMilliseconds << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::cout << r2::tab << "tick = GetTickCount();" << r2::linefeed;
						std::cout << r2::tab2 << current_tick << r2::linefeed;

						last_tick = current_tick;
					}

					std::cout << r2::split;

					{
						std::cout << r2::tab << "GetTickCount64();" << r2::linefeed;
						std::cout << r2::tab2 << GetTickCount64() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::cout << r2::tab << "timeGetTime();" << r2::linefeed;
						std::cout << r2::tab2 << timeGetTime() << r2::linefeed;
					}

					std::cout << r2::split;
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
}