#include "pch.h"
#include "align_test.h"

#include "r2_eTestResult.h"

namespace align_test
{
	r2::iTest::TitleFunc Align_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 0";
		};
	}
	r2::iTest::DoFunc Align_0::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				int i = 1;
				void* ip = &i;
				std::size_t space = sizeof( i );

				std::cout << "\t" << "int i = 1;" << r2::linefeed;
				std::cout << "\t" << "void* ip = &i;" << r2::linefeed;
				std::cout << "\t\t - " << "adress of ip : " << ip << r2::linefeed;
				std::cout << "\t\t - " << "space : " << space << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				{
					std::cout << "\t" << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << "\t\t - " << "success" << r2::linefeed;
					}
					else
					{
						std::cout << "\t\t - " << "failed" << r2::linefeed;
					}

					{
						std::cout << "\t\t - " << "adress of ip : " << ip << r2::linefeed;
						std::cout << "\t\t - " << "space : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					int move_amount = 3;

					char* cp = static_cast<char*>( ip );
					cp += move_amount;

					ip = cp;
					space -= sizeof( char ) * move_amount;

					std::cout << "\t" << "move " << move_amount << r2::linefeed;
					std::cout << "\t\t - " << "adress of ip : " << ip << r2::linefeed;
					std::cout << "\t\t - " << "space : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << "\t" << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << "\t\t - " << "success" << r2::linefeed;
					}
					else
					{
						std::cout << "\t\t - " << "failed" << r2::linefeed;
					}

					{
						std::cout << "\t\t - " << "adress of ip : " << ip << r2::linefeed;
						std::cout << "\t\t - " << "space : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					int move_amount = 1;

					char* cp = static_cast<char*>( ip );
					cp += move_amount;

					ip = cp;
					space -= sizeof( char ) * move_amount;

					std::cout << "\t" << "move " << move_amount << r2::linefeed;
					std::cout << "\t\t - " << "adress of ip : " << ip << r2::linefeed;
					std::cout << "\t\t - " << "space : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << "\t" << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << "\t\t - " << "success" << r2::linefeed;
					}
					else
					{
						std::cout << "\t\t - " << "failed" << r2::linefeed;
					}

					{
						std::cout << "\t\t - " << "adress of ip : " << ip << r2::linefeed;
						std::cout << "\t\t - " << "space : " << space << r2::linefeed;
						std::cout << r2::linefeed;
					}
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}


	r2::iTest::TitleFunc Align_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 1";
		};
	}
	r2::iTest::DoFunc Align_1::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				double d = 1;
				void* dp = &d;
				std::size_t space = sizeof( double );

				std::cout << "\t" << "double d;" << r2::linefeed;
				std::cout << "\t" << "void* dp = &d;" << r2::linefeed;
				std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
				std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				{
					std::cout << "\t" << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << "\t\t - " << "success" << r2::linefeed;
					}
					else
					{
						std::cout << "\t\t - " << "failed" << r2::linefeed;
					}

					{
						std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
						std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					const int move_amount = 1;

					char* cp = static_cast<char*>( dp );
					cp += move_amount;

					dp = cp;
					space -= sizeof( char );

					std::cout << "\t" << "move " << move_amount << r2::linefeed;
					std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
					std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << "\t" << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << "\t\t - " << "success" << r2::linefeed;
					}
					else
					{
						std::cout << "\t\t - " << "failed" << r2::linefeed;
					}

					{
						std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
						std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					const int move_amount = 1;

					char* cp = static_cast<char*>( dp );
					cp += move_amount;

					dp = cp;
					space -= sizeof( char );

					std::cout << "\t" << "move " << move_amount << r2::linefeed;
					std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
					std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << "\t" << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << "\t\t - " << "success" << r2::linefeed;
					}
					else
					{
						std::cout << "\t\t - " << "failed" << r2::linefeed;
					}

					{
						std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
						std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
						std::cout << r2::linefeed;
					}
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}


	
	r2::iTest::TitleFunc Align_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 2";
		};
	}
	r2::iTest::DoFunc Align_2::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				char buffer[] = "------------------------";
				void * pt = buffer;

				std::cout << "\t + " << "orig : " << buffer << r2::linefeed;
				std::cout << "\t + " << "adress of pt : " << pt << r2::linefeed << r2::linefeed;

				std::cout << "\t + " << "Process" << r2::linefeed;

				std::size_t space = sizeof( buffer ) - 1;
				while( std::align( alignof( int ), sizeof( char ), pt, space ) )
				{
					std::cout << "\t\t - " << "old adress of pt : " << pt << r2::linefeed;

					if( !std::align( alignof( int ), sizeof( char ), pt, space ) )
					{
						break;
					}

					char* temp = static_cast<char*>( pt );
					*temp = '*';
					++temp;
					space -= sizeof( char );

					pt = temp;

					std::cout << "\t\t - " << "convert : " << buffer << r2::linefeed;
					std::cout << "\t\t - " << "new adress of pt : " << pt << r2::linefeed;
					std::cout << r2::linefeed;
				}

				std::cout << "\t" << "result : " << buffer << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}