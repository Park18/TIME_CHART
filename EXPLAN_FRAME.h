#pragma once
#include "BASE_FRAME.h"
class EXPLAN_FRAME : public BASE_FRAME
{
public:
	EXPLAN_FRAME();

	// BASE_FRAME��(��) ���� ��ӵ�
	virtual void Set_Frame() override;
	virtual void Frame_Display() override;
	virtual void Frame_Display(MAKING_CHART* making_chart) override;

	void Explan_Display();
};

