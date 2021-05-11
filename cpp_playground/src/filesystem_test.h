#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace filesystem_test
{
	class DirectoryPath : public r2::iTest, public r2::SingleTon<DirectoryPath>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};



	class DirectoryIterator : public r2::iTest, public r2::SingleTon<DirectoryIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};



	class RecursiveDirectoryIterator : public r2::iTest, public r2::SingleTon<RecursiveDirectoryIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};



	class PathOperation : public r2::iTest, public r2::SingleTon<PathOperation>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};
}