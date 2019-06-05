#pragma once
#ifndef __START_FRAME_H
#define __START_FRAME_H

#include "BASE_FRAME.h"
#include "MAKING_FRAME.h"
#include "VIEW_CHART_FRAME.h"
#include "EXPLAN_FRAME.h"

#include "MAKING_CHART.h"

class START_FRAME : public BASE_FRAME
{
private:
	MAKING_FRAME making_frame;			// 제작창
	VIEW_CHART_FRAME view_chart_frame;	// 시간표 조회창
	EXPLAN_FRAME explan_frame;			// 설명창

	MAKING_CHART making_chart;			// 시간표 제작 객체

public:
	START_FRAME();

	// BASE_FRAME을(를) 통해 상속됨
	virtual void Set_Frame() override;
	virtual void Frame_Display() override;
	virtual void Frame_Display(MAKING_CHART* making_chart) override;
};


#endif // !__START_FRAME_H

