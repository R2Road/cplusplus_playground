﻿#include <Windows.h>

#include "r2_Director.h"
#include "r2_Scene.h"

int main()
{
	SetConsoleTitle( TEXT( "cpp_playground" ) );
	system( "mode con lines=60 cols=120" );

	r2::Director director;
	director.Setup<r2::Scene>();

	director.Update();

	return 0;
}
