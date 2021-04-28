#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace random_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class StatusSaveAndLoad : public r2::iTest, public r2::SingleTon<StatusSaveAndLoad>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}