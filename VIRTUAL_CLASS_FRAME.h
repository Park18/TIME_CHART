#pragma once
#ifndef __VIRTUAL_CLASS_FRAME_H
#define __VIRTUAL_CLASS_FRAME_H

#include "BASE_FRAME.h"
#include "VIRTUAL_CLASS.h"

class VIRTUAL_CLASS_FRAME : public BASE_FRAME
{
private:
	VIRTUAL_CLASS virtual_class;

public:
	VIRTUAL_CLASS_FRAME();

	// BASE_FRAME을(를) 통해 상속됨
	virtual void Set_Frame() override;
	virtual void Frame_Display() override;
	virtual void Frame_Display(MAKING_CHART* making_chart) override;
};

#endif // !__VIRTUAL_CLASS_FRAME_H