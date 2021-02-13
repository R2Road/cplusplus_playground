#include "filesystem_test.h"

#include <filesystem>
#include <iostream>

namespace
{
	void TestGetDirectoryPath()
	{
		std::cout << "== Current Directory ==" << std::endl;

		std::filesystem::path cwd = std::filesystem::current_path();

		std::cout << "\t" << cwd << std::endl;
		std::cout << std::endl;



		std::cout << "== Temp Directory ==" << std::endl;

		std::filesystem::path cwd2 = std::filesystem::temp_directory_path();

		std::cout << "\t" << cwd2 << std::endl;
		std::cout << std::endl;
	}

	void TestDirectoryIterator()
	{
		std::cout << "== Directory Iterator ==" << std::endl;

		std::cout << "\t" << "+ Directory : " << std::endl;
		std::cout << "\t\t" << std::filesystem::current_path() << std::endl;
		std::cout << std::endl;

		std::cout << "\t" << "+ View" << std::endl;
		std::filesystem::directory_iterator itr( std::filesystem::current_path() );
		for( auto i : itr )
		{
			std::cout << "\t\t" << i.path() << std::endl;
			std::cout << "\t\t\t" << ( std::filesystem::is_regular_file( i.path() ) ? "file" : "directory" ) << std::endl;
		}

		std::cout << std::endl;
	}

	void TestRecursiveDirectoryIterator()
	{
		std::cout << "== Recursive Directory Iterator ==" << std::endl;

		std::filesystem::recursive_directory_iterator itr( std::filesystem::current_path() / "src" );
		for( auto i : itr )
		{
			std::cout << "\t" << i.path() << std::endl;
		}

		std::cout << std::endl;
	}

	void TestPathOperation()
	{
		std::cout << "== Path Operation ==" << std::endl;

		std::filesystem::path cwd = std::filesystem::current_path();
		std::cout << "\t" << "+ Directory : " << std::endl;
		std::cout << "\t\t" << cwd << std::endl;
		std::cout << std::endl;



		std::cout << "\t" << "+ Append, Operator /" << std::endl;

		cwd /= "test.txt";

		std::cout << "\t\t" << cwd << std::endl;
		std::cout << std::endl;



		std::cout << "\t" << "+ Remove File Name" << std::endl;

		cwd.remove_filename();

		std::cout << "\t\t" << cwd << std::endl;
		std::cout << std::endl;
	}
}

namespace filesystem_test
{
	void CurrentDirectory::Do()
	{
		TestGetDirectoryPath();

		std::cout << std::endl << std::endl;

		TestDirectoryIterator();

		std::cout << std::endl << std::endl;

		TestRecursiveDirectoryIterator();

		std::cout << std::endl << std::endl;

		TestPathOperation();
	}
}