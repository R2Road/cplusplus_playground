#include "optional_test.h"

#include <iostream>
#include <optional>

namespace
{
	struct TestStruct
	{
		TestStruct() { std::cout << "- Call : TestStruct::TestStruct()"; }
		TestStruct( const int i ) : I( i ) { std::cout << "- Call : TestStruct::TestStruct( const int i )"; }
		TestStruct( const TestStruct& ) { std::cout << "- Call : TestStruct::TestStruct( const TestStruct& )"; }

		int I = 111;
	};

	static const TestStruct test_structs[2] = { { 222 }, { 333 } };

	std::optional<TestStruct> GetTestStruct( const std::size_t index )
	{
		if( 2 > index )
		{
			return test_structs[index];
		}
		else
		{
			return std::nullopt;
		}
	}
}
namespace optional_test
{
	void Basic::Do()
	{
		std::cout << "== Optional : Basic ==" << std::endl;


		std::cout << "\t+ Make Test Struct" << std::endl;
		std::cout << "\t\t- TestStruct ts;" << std::endl;
		std::cout << "\t\t\t";
		TestStruct ts;
		std::cout << std::endl;


		std::cout << std::endl << std::endl;


		std::cout << "\t+ Make Optional" << std::endl;
		std::cout << "\t\t- std::optional<TestStruct> op_ts;" << std::endl;
		std::optional<TestStruct> op_ts;
		std::cout << "\t\t- Call : has_value()" << std::endl;
		std::cout << "\t\t\t" << op_ts.has_value() << std::endl;
		//std::cout << "\t\t\t" << op_ts.value().i << std::endl; // throw exception : op_ts is nullopt


		std::cout << std::endl << std::endl;


		std::cout << "\t+ Assign 2 Optional " << std::endl;
		std::cout << "\t\t- op_ts = ts" << std::endl;
		std::cout << "\t\t\t";
		op_ts = ts;
		std::cout << std::endl;
		std::cout << "\t\t- Call : has_value()" << std::endl;
		std::cout << "\t\t\t" << op_ts.has_value() << std::endl;


		std::cout << std::endl << std::endl;


		std::cout << "\t+ Value() " << std::endl;
		std::cout << "\t\t- op_ts.value().I;" << std::endl;
		std::cout << "\t\t\t" << op_ts.value().I << std::endl;


		std::cout << std::endl << std::endl;


		bool has_value = false;
		std::cout << "\t+ GetTestStruct() " << std::endl;
		{
			std::cout << "\t\t- GetTestStruct( 0 );" << std::endl;
			std::cout << "\t\t\t";
			const auto result = GetTestStruct( 0 );
			std::cout << "\t\t- Call : has_value()" << std::endl;
			std::cout << "\t\t\t" << result.has_value() << std::endl;
		}
		{
			std::cout << "\t\t- GetTestStruct( 1 );" << std::endl;
			std::cout << "\t\t\t";
			const auto result = GetTestStruct( 1 );
			std::cout << "\t\t- Call : has_value()" << std::endl;
			std::cout << "\t\t\t" << result.has_value() << std::endl;
		}
		{
			std::cout << "\t\t- GetTestStruct( 2 );" << std::endl;
			const auto result = GetTestStruct( 2 );
			std::cout << "\t\t- Call : has_value()" << std::endl;
			std::cout << "\t\t\t" << result.has_value() << std::endl;
		}


		std::cout << std::endl << std::endl;
	}
}