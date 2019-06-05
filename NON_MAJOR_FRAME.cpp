#include "NON_MAJOR_FRAME.h"

NON_MAJOR_FRAME::NON_MAJOR_FRAME()
{
	Set_Frame();
}

void NON_MAJOR_FRAME::Set_Frame()
{
	console_ui.Set_Title("출력 범위 선택");

	console_ui.Insert_Menu("공          통");
	console_ui.Insert_Menu("일          반");
	console_ui.Insert_Menu("나    가    기");
}

void NON_MAJOR_FRAME::Frame_Display()
{
}

void NON_MAJOR_FRAME::Frame_Display(MAKING_CHART* making_chart)
{
	while (1)
	{
		system("cls");

		console_ui.Title_Display(49);
		console_ui.Menu_Display();
		console_ui.Class_Point_Display(making_chart);

		int mode = console_ui.Control_Arrow();

		switch (mode)
		{
		case STD_MENU_Y:		// 공통
			console_ui.Lecture_List_Display(making_chart, &non_major, PUBLIC, 6);
			continue;

		case STD_MENU_Y + 2:	// 일반
			console_ui.Lecture_List_Display(making_chart, &non_major, NORMAL, 6);
			continue;

		case STD_MENU_Y + 4:	// 나가기
		case BACK:
			break;
		}

		break;
	}
}
