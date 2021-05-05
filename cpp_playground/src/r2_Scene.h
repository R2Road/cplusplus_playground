#pragma once

#include <functional>
#include <memory>
#include <string_view>
#include <vector>

namespace r2
{
	enum class eTestResult; 

	class iTest;
	class Director;

	using SceneUp = std::unique_ptr<class Scene>;
	class Scene
	{
	private:
		struct TestInfo
		{
			TestInfo(
				const char key_code
				, const std::function<const char*( )> name_function
				, const std::function<const r2::eTestResult()> test_function
			) :
				KeyCode( key_code )
				, NameFunction( name_function )
				, TestFunction( test_function )
			{}

			char KeyCode;
			std::function<const char*()> NameFunction;
			std::function<const r2::eTestResult()> TestFunction;
		};

		using TestContainerT = std::vector<TestInfo>;

	public:
		Scene( Director& director, const char* title_string, const char* description_string = "" );
		virtual ~Scene() {}

		void ShowTitle() const;
		void ShowDescription() const;
		void ShowMenu() const;

		eTestResult Do( const int key_code );

		void AddChild( const char key_code, const iTest& test_obj );
		void AddChild( const char key_code, const std::function<const char*( )> func_title, const std::function<const r2::eTestResult()> func_test );
		void AddSplit();

	protected:
		Director& mDirector;
		std::string_view mTitleString;
		std::string_view mDescriptionString;

		TestContainerT mTests;
	};
}