#include "pch.h"
#include "alignof_test.h"

#include <deque>
#include <memory>
#include <unordered_map>
#include <vector>

#include "base/r2_eTestResult.h"

namespace alignof_test
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
				std::cout << "\t" << "+ align of char : " << alignof( char ) << r2::linefeed;
				std::cout << "\t\t" << "- size of char : " << sizeof( char ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of int : " << alignof( int ) << r2::linefeed;
				std::cout << "\t\t" << "- size of int : " << sizeof( int ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of bool : " << alignof( bool ) << r2::linefeed;
				std::cout << "\t\t" << "- size of bool : " << sizeof( bool ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of double : " << alignof( double ) << r2::linefeed;
				std::cout << "\t\t" << "- size of double : " << sizeof( double ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				struct EmptyStruct {};

				struct IntFloatCharStruct
				{
					int i;
					float f;
					char c;
				};

				struct CharCharCharStruct
				{
					char c1;
					char c2;
					char c3;
				};

				struct CharDoubleStruct
				{
					char c;
					double d;
				};

				struct CharBoolStruct
				{
					char c;
					bool b;
				};

				struct CharIntDoubleStruct
				{
					char c;
					int i;
					double d;
				};

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of IntFloatCharStruct : " << alignof( IntFloatCharStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of IntFloatCharStruct : " << sizeof( IntFloatCharStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharCharCharStruct : " << alignof( CharCharCharStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharCharCharStruct : " << sizeof( CharCharCharStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharDoubleStruct : " << alignof( CharDoubleStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharDoubleStruct : " << sizeof( CharDoubleStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharBoolStruct : " << alignof( CharBoolStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharBoolStruct : " << sizeof( CharBoolStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharIntDoubleStruct : " << alignof( CharIntDoubleStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharIntDoubleStruct : " << sizeof( CharIntDoubleStruct ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ align of std::list<char> : " << alignof( std::list<char> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::list<char> : " << sizeof( std::list<char> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::list<int> : " << alignof( std::list<int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::list<int> : " << sizeof( std::list<int> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::vector<int> : " << alignof( std::vector<int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::vector<int> : " << sizeof( std::vector<int> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::alignof( std::unordered_map<int, int> ) : " << alignof( std::unordered_map<int, int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::unordered_map<int, int> : " << sizeof( std::unordered_map<int, int> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::alignof( std::deque<int> ) : " << alignof( std::deque<int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::deque<int> : " << sizeof( std::deque<int> ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc MixedStruct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mixed Struct";
		};
	}
	r2::iTest::DoFunc MixedStruct::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			struct EmptyStruct {};

			struct CharIntFloatStruct
			{
				char c;
				int i;
				float f;
			};

			struct DoubleStruct
			{
				double d;
			};


			struct Mixed_1_Empty_N_CIF_Struct
			{
				EmptyStruct e;
				CharIntFloatStruct c;
			};

			struct Mixed_2_Empty_N_D_Struct
			{
				EmptyStruct e;
				DoubleStruct c;
			};

			struct Mixed_3_Empty_N_CIF_D_Struct
			{
				EmptyStruct e;
				CharIntFloatStruct c;
				DoubleStruct d;
			};

			{
				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of DoubleStruct : " << alignof( DoubleStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of DoubleStruct : " << sizeof( DoubleStruct ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ align of Mixed_1_Empty_N_CIF_Struct : " << alignof( Mixed_1_Empty_N_CIF_Struct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of Mixed_1_Empty_N_CIF_Struct : " << sizeof( Mixed_1_Empty_N_CIF_Struct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of Mixed_2_Empty_N_D_Struct : " << alignof( Mixed_2_Empty_N_D_Struct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of Mixed_2_Empty_N_D_Struct : " << sizeof( Mixed_2_Empty_N_D_Struct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of Mixed_3_Empty_N_CIF_D_Struct : " << alignof( Mixed_3_Empty_N_CIF_D_Struct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of Mixed_3_Empty_N_CIF_D_Struct : " << sizeof( Mixed_3_Empty_N_CIF_D_Struct ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}