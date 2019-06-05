#pragma once
#ifndef __MAJOR_FRAME_H
#define __MAJOR_FRAME_H

#include "BASE_FRAME.h"
#include "MAJOR.h"

class MAJOR_FRAME : public BASE_FRAME
{
private:
	MAJOR major;

public:
	MAJOR_FRAME();

	// BASE_FRAME��(��) ���� ��ӵ�
	virtual void Set_Frame() override;
	virtual void Frame_Display() override;
	virtual void Frame_Display(MAKING_CHART* making_chart) override;
};

#endif // !__MAJOR_FRAME_H


