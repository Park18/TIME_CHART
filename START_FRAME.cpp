#include "START_FRAME.h"

START_FRAME::START_FRAME()
{
	Set_Frame();
}

void START_FRAME::Set_Frame()
{
	console_ui.Set_Title("시 간 표 제 작 하 기");

	console_ui.Insert_Menu("시 간 표 제 작");
	console_ui.Insert_Menu("시 간 표 조 회");
	console_ui.Insert_Menu("설          명");
	console_ui.Insert_Menu("종          료");

	making_chart.read_base_to_arr(BASE_CHART);		// 기본 시간표형식을 읽는 메서드
}

void START_FRAME::Frame_Display()
{
	while (1)
	{
		system("cls");

		console_ui.Title_Display(48);
		console_ui.Menu_Display();

		int mode = console_ui.Control_Arrow();

		switch (mode)
		{
		case STD_MENU_Y:		// 시간표 제작
			making_frame.Frame_Display(&making_chart);
			break;

		case STD_MENU_Y + 2:	// 시간표 조회
			view_chart_frame.Frame_Display(&making_chart);
			break;

		case STD_MENU_Y + 4:	// 설명
			explan_frame.Frame_Display();
			break;

		case STD_MENU_Y + 6:	// 종료
			exit(0);
		}
	}
}

void START_FRAME::Frame_Display(MAKING_CHART* making_chart)
{
}
