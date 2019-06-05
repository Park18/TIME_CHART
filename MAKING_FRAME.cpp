#include "MAKING_FRAME.h"

MAKING_FRAME::MAKING_FRAME()
{
	Set_Frame();
}

void MAKING_FRAME::Set_Frame()
{
	console_ui.Set_Title("분야 선택");

	console_ui.Insert_Menu("전          공");
	console_ui.Insert_Menu("교          양");
	console_ui.Insert_Menu("가          상");
	console_ui.Insert_Menu("나    가    기");
}

void MAKING_FRAME::Frame_Display()
{
}

void MAKING_FRAME::Frame_Display(MAKING_CHART* making_chart)
{
	while (1)
	{
		system("cls");

		console_ui.Title_Display(52);
		console_ui.Menu_Display();
		console_ui.Class_Point_Display(making_chart);

		int mode = console_ui.Control_Arrow();

		switch (mode)
		{
		case STD_MENU_Y:		// 전공
			major_frame.Frame_Display(making_chart);
			continue;

		case STD_MENU_Y + 2:	// 교양
			non_major_frame.Frame_Display(making_chart);
			continue;

		case STD_MENU_Y + 4:	// 가상
			virtual_class_frame.Frame_Display(making_chart);
			continue;

		case STD_MENU_Y + 6:	// 나가기
		case BACK:
			break;
		}

		break;
	}
}
