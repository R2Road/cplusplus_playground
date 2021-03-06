#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace align_test
{
	class Align_0 : public r2::iTest, public r2::SingleTon<Align_0>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Align_1 : public r2::iTest, public r2::SingleTon<Align_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Align_2 : public r2::iTest, public r2::SingleTon<Align_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}