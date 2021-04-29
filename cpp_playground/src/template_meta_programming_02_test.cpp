#include "pch.h"
#include "template_meta_programming_02_test.h"

#include <string>

#include "r2_eTestResult.h"

namespace template_meta_programming_test
{
	template<char... chars>
	struct ConvertCharacter2String_1
	{
		static constexpr size_t size = sizeof...( chars );
		static constexpr const char c[size + 1] = { chars..., '\0' };
	};

	const r2::iTest::TitleFunc Character2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Character 2 String";
		};
	}
	const r2::iTest::DoFunc Character2String::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::size" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::size << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::c << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}





namespace
{
	template<int N>
	struct ConvertInteger2String_1
	{
		static std::string c;
	};
	template<int N> std::string ConvertInteger2String_1<N>::c = std::to_string( N );
}
namespace template_meta_programming_test
{
	const r2::iTest::TitleFunc Integer2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Integer 2 String";
		};
	}
	const r2::iTest::DoFunc Integer2String::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ ConvertInteger2String_1<2468>::c.c_str()" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertInteger2String_1<2468>::c.c_str() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}




namespace
{
	template<int N>
	struct CalculatePlaceValue4Integer
	{
		static constexpr size_t place_value = ( N > 0 ? 1 : 0 ) + CalculatePlaceValue4Integer<N / 10>::place_value;
	};
	template<>
	struct CalculatePlaceValue4Integer<0>
	{
		static constexpr size_t place_value = 0;
	};
}
namespace template_meta_programming_test
{
	const r2::iTest::TitleFunc CalculatePlaceValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Place Value 4 Integer";
		};
	}
	const r2::iTest::DoFunc CalculatePlaceValue::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ CalculatePlaceValue<1>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<1>::place_value << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ CalculatePlaceValue<100>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<100>::place_value << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ CalculatePlaceValue<123456>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<123456>::place_value << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}





namespace
{
	template<int U>
	struct ConvertUnits2Character
	{
		static constexpr const char c = '0' + U;
	};


	template<int N, char... Chars>
	struct ConvertInteger2String_2;

	template<char... Chars>
	struct ConvertInteger2String_2<0, Chars...>
	{
		static constexpr size_t size = ( sizeof...( Chars ) ) + 8 + 1;
		static constexpr const char c[size] = { Chars..., ' ', 'M', 'O', 'O', 'Y', 'A', 'H', 'O', '\0' };
		static constexpr const char* str = c;
	};

	template<int N, char... Chars>
	struct ConvertInteger2String_2
	{
		static constexpr size_t size = ConvertInteger2String_2<N / 10, ConvertUnits2Character<N % 10>::c, Chars...>::size;
		static constexpr const char* str = ConvertInteger2String_2<N / 10, ConvertUnits2Character<N % 10>::c, Chars...>::str;
	};
}
namespace template_meta_programming_test
{
	const r2::iTest::TitleFunc Integer2String_II::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Integer 2 String II";
		};
	}
	const r2::iTest::DoFunc Integer2String_II::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "+ Units 2 Character" << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ ConvertUnits2Character<1>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<1>::c << r2::linefeed << r2::linefeed;


				std::cout << "\t" << "+ ConvertUnits2Character<9>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<9>::c << r2::linefeed << r2::linefeed;


				std::cout << "\t" << "+ ConvertUnits2Character<10>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<10>::c << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ Integer 2 String II" << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ ConvertInteger2String_2<101010>" << r2::linefeed;
				std::cout << "\t\t" << "size : " << ConvertInteger2String_2<101010>::size << r2::linefeed;
				std::cout << "\t\t" << "string : " << ConvertInteger2String_2<101010>::str << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}