#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace align_test
{
	class AlignAs : public r2::iNode, public r2::SingleTon<AlignAs>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}