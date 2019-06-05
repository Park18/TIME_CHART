#pragma once
#ifndef __MAKING_FRAME_H
#define __MAKING_FRAME_H	

#include "BASE_FRAME.h"
#include "MAJOR_FRAME.h"
#include "NON_MAJOR_FRAME.h"
#include "VIRTUAL_CLASS_FRAME.h"

class MAKING_FRAME : public BASE_FRAME
{
private:
	MAJOR_FRAME major_frame;
	NON_MAJOR_FRAME non_major_frame;
	VIRTUAL_CLASS_FRAME virtual_class_frame;

public:
	MAKING_FRAME();

	// BASE_FRAME을(를) 통해 상속됨
	virtual void Set_Frame() override;
	virtual void Frame_Display() override;
	virtual void Frame_Display(MAKING_CHART* making_chart) override;
};

#endif // !__MAKING_FRAME_H

