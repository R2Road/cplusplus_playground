#include "shared_pointer_test.h"

#include <iostream>
#include <memory>

namespace
{
	void Test1()
	{
		std::cout << "== Shared Pointer ==" << std::endl;

		std::shared_ptr<int> test_sp( new int( 10 ) );
		std::cout << "\t" << "+ Make Sp" << std::endl;
		std::cout << "\t\t" << "+ std::shared_ptr<int> test_sp( new int( 10 ) )" << std::endl;
		std::cout << "\t\t\t" << *test_sp << std::endl;
		std::cout << std::endl;

		const auto test_sp_2 = test_sp;
		std::cout << "\t" << "+ Copy To Const Sp" << std::endl;
		std::cout << std::endl;

		*test_sp_2 = 11;
		std::cout << "\t" << "+ Change Value with Const Sp" << std::endl;
		std::cout << "\t\t" << *test_sp_2 << std::endl;
		std::cout << std::endl;
	}

	void Test2()
	{
		std::cout << "== Shared Pointer Has Const Value ==" << std::endl;

		std::shared_ptr<const int> const_test_sp( new int( 10 ) );
		std::cout << "\t" << "+ Make Sp Has Const Value" << std::endl;
		std::cout << "\t\t" << "+ std::shared_ptr<const int> test_sp( new int( 10 ) )" << std::endl;
		std::cout << "\t\t\t" << *const_test_sp << std::endl;
		std::cout << std::endl;

		std::cout << "\t" << "+ Failed : Change Value" << std::endl;
		std::cout << std::endl;

		//*const_test_sp = 11;
		//std::cout << "\t" << "+ Change Value with Sp Has Const Value" << std::endl;
		//std::cout << "\t\t" << *const_test_sp << std::endl;
	}
}

namespace shared_pointer_test
{
	void SharedPtr::Do()
	{
		Test1();

		std::cout << std::endl << std::endl;

		Test2();
	}
}