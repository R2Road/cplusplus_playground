﻿#include <conio.h>
#include <iostream>
#include <sstream>
#include <Windows.h>

#include "random_test_StatusSaveAndLoad.h"

std::string MakeMenuString()
{
	std::stringstream ss;
	ss << "+ Menu" << std::endl;
	ss << "1 : random_test::Status_Save_And_Load" << std::endl;

	ss << std::endl << "Press Number" << std::endl;

	return std::string( ss.str() );
}

void ShowMenu()
{
	static std::string menu_string( std::move( MakeMenuString() ) );
	std::cout << menu_string;
}

int main()
{
	system( "mode con lines=50 cols=120" );

	int input = 0;
	while( true )
	{
		ShowMenu();

		input = _getch();
		system( "cls" );

		switch( input )
		{
		case '1':
			random_test::StatusSaveAndLoad();
			break;

		case 27: // ESC
			return 0;
		}

		std::cout << std::endl << "Press Any Key" << std::endl;
		_getch();
		system( "cls" );
	}

	return 0;
}
