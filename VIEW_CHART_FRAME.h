#pragma once
#ifndef __VIEW_CHART_FRAME_H
#define __VIEW_CHART_FRAME_H

#include "BASE_FRAME.h"

#define VIEW_CHART "TIME_CHART/TIME_CHART.csv"

#define MON_X 30
#define TUE_X 48
#define WED_X 66
#define THR_X 80
#define FRI_X 96

#define MAX_ROWS_SIZE 19
#define MAX_COLS_SIZE 7

class VIEW_CHART_FRAME : public BASE_FRAME
{
private:
	std::string chart_table[19][7];

public:
	// BASE_FRAME을(를) 통해 상속됨
	virtual void Set_Frame() override;
	virtual void Frame_Display() override; 
	virtual void Frame_Display(MAKING_CHART* making_chart) override;

	void Explan_Display();
	void Chart_Display(MAKING_CHART* making_chart);
};


#endif // !__VIEW_CHART_FRAME_H

