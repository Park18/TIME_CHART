#pragma once
#ifndef __BASE_FRAME_H
#define __BASE_FRAME_H

#include "CONSOLE_UI.h"
#include "MAKING_CHART.h"

class BASE_FRAME
{
protected:
	CONSOLE_UI console_ui;
	MAKING_CHART making_chart;

public:
	virtual void Set_Frame() = 0;
	virtual void Frame_Display() = 0;
	virtual void Frame_Display(MAKING_CHART* making_chart) = 0;
};

#endif // !__BASE_FRAME_H
