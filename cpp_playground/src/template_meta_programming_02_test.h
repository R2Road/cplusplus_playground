#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace template_meta_programming_test
{
	class Character2String : public r2::iTest, public r2::SingleTon<Character2String>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};


	class Integer2String : public r2::iTest, public r2::SingleTon<Integer2String>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};


	class CalculatePlaceValue : public r2::iTest, public r2::SingleTon<CalculatePlaceValue>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};


	class Integer2String_II : public r2::iTest, public r2::SingleTon<Integer2String_II>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}