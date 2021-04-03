#include "r2_Director.h"

#include <utility>

namespace r2
{
	Director::Director() : mScene()
	{}

	void Director::Setup( SceneUp scene )
	{
		mScene = std::move( scene );
	}

	bool Director::Update()
	{
		mScene->Do();

		return true;
	}
}