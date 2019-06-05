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
	MAKING_FRAME making_frame;			// ����â
	VIEW_CHART_FRAME view_chart_frame;	// �ð�ǥ ��ȸâ
	EXPLAN_FRAME explan_frame;			// ����â

	MAKING_CHART making_chart;			// �ð�ǥ ���� ��ü

public:
	START_FRAME();

	// BASE_FRAME��(��) ���� ��ӵ�
	virtual void Set_Frame() override;
	virtual void Frame_Display() override;
	virtual void Frame_Display(MAKING_CHART* making_chart) override;
};


#endif // !__START_FRAME_H

