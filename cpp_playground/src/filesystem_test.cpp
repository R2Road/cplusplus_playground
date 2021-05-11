#include "pch.h"
#include "filesystem_test.h"

#include <filesystem>
#include <stdlib.h>

#include "r2_eTestResult.h"

namespace filesystem_test
{

	r2::iTest::TitleFunc DirectoryPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directory Path";
		};
	}
	r2::iTest::DoFunc DirectoryPath::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Current Directory" << r2::linefeed;

				std::filesystem::path p = std::filesystem::current_path();

				std::cout << "\t\t" << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Temp Directory" << r2::linefeed;

				std::filesystem::path p2 = std::filesystem::temp_directory_path();

				std::cout << "\t\t" << p2 << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace filesystem_test
{

	r2::iTest::TitleFunc DirectoryIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directory Iterator";
		};
	}
	r2::iTest::DoFunc DirectoryIterator::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Directory : " << r2::linefeed;
				std::cout << "\t\t" << std::filesystem::current_path() << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t" << "+ View" << r2::linefeed;
				std::filesystem::directory_iterator itr( std::filesystem::current_path() );
				for( auto i : itr )
				{
					std::cout << "\t\t" << i.path() << r2::linefeed;
					std::cout << "\t\t\t" << ( std::filesystem::is_regular_file( i.path() ) ? "file" : "directory" ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace filesystem_test
{

	r2::iTest::TitleFunc RecursiveDirectoryIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Recursive Directory Iterator";
		};
	}
	r2::iTest::DoFunc RecursiveDirectoryIterator::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int i = 0;

				std::filesystem::recursive_directory_iterator itr( std::filesystem::current_path() / "src" );
				for( auto p : itr )
				{
					std::cout << "\t" << p.path() << r2::linefeed;

					++i;
					if( i > 40 )
					{
						i = 0;
						system( "pause" );
					}
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace filesystem_test
{

	r2::iTest::TitleFunc PathOperation::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Path Operation";
		};
	}
	r2::iTest::DoFunc PathOperation::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::filesystem::path p = std::filesystem::current_path();

			{
				std::cout << "\t" << "+ Directory : " << r2::linefeed << r2::linefeed;
				std::cout << "\t\t" << p << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Append with Operator /" << r2::linefeed;

				p /= "test.txt";
				std::cout << "\t\t" << "p /= \"test.txt\"" << r2::linefeed;

				std::cout << "\t\t\t" << p << r2::linefeed;
				std::cout << r2::linefeed;


				std::cout << "\t" << "+ Remove File Name" << r2::linefeed;

				p.remove_filename();
				std::cout << "\t\t" << "p.remove_filename();" << r2::linefeed;
				std::cout << "\t\t\t" << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Remove File Name And Separator" << r2::linefeed;

				p /= "test.txt";
				std::cout << "\t\t\t" << "orig : " << p << r2::linefeed << r2::linefeed;

				p._Remove_filename_and_separator();
				std::cout << "\t\t" << "p._Remove_filename_and_separator();" << r2::linefeed;
				std::cout << "\t\t\t" << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Replace Extension" << r2::linefeed;

				p /= "test.txt";
				std::cout << "\t\t\t" << "orig : " << p << r2::linefeed << r2::linefeed;

				p.replace_extension( "json" );
				std::cout << "\t\t" << "p.replace_extension( \"json\" );" << r2::linefeed;
				std::cout << "\t\t\t" << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Replace File Name" << r2::linefeed;

				std::cout << "\t\t\t" << "orig : " << p << r2::linefeed << r2::linefeed;

				p.replace_filename( "new_filename" );
				std::cout << "\t\t" << "p.replace_filename( \"new_filename\" );" << r2::linefeed;
				std::cout << "\t\t\t" << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}