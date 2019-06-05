#pragma once
#ifndef __NON_MAJOR_FRAME_H
#define __NON_MAJOR_FRAME_H

#include "BASE_FRAME.h"
#include "NON_MAJOR.h"

class NON_MAJOR_FRAME : public BASE_FRAME
{
private:
	NON_MAJOR non_major;

public:
	NON_MAJOR_FRAME();

	// BASE_FRAME을(를) 통해 상속됨
	virtual void Set_Frame() override;
	virtual void Frame_Display() override;
	virtual void Frame_Display(MAKING_CHART* making_chart) override;
};


#endif // !__NON_MAJOR_FRAME_H

