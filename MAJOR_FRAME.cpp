#include "MAJOR_FRAME.h"


MAJOR_FRAME::MAJOR_FRAME()
{
	Set_Frame();
}

void MAJOR_FRAME::Set_Frame()
{
	console_ui.Set_Title("출력 범위 선택");

	console_ui.Insert_Menu("1     학    년");
	console_ui.Insert_Menu("2     학    년");
	console_ui.Insert_Menu("3     학    년");
	console_ui.Insert_Menu("4     학    년");
	console_ui.Insert_Menu("전          체");
	console_ui.Insert_Menu("나    가    기");
}

void MAJOR_FRAME::Frame_Display()
{
}

void MAJOR_FRAME::Frame_Display(MAKING_CHART* making_chart)
{
	//major.Read_File_Open(SECURITY_INFORMATION);

	while (1)
	{
		system("cls");

		console_ui.Title_Display(49);
		console_ui.Menu_Display();
		console_ui.Class_Point_Display(making_chart);

		int mode = console_ui.Control_Arrow();

		switch (mode)
		{
		case STD_MENU_Y:		// 1학년
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 1);
			continue;

		case STD_MENU_Y + 2:	// 2학년
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 2);
			continue;

		case STD_MENU_Y + 4:	// 3학년
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 3);
			continue;

		case STD_MENU_Y + 6:	// 4학년
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 4);
			continue;

		case STD_MENU_Y + 8:	// 전체
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 6);
			continue;

		case STD_MENU_Y + 10:	// 나가기
			break;
		}

		break;
	}
}
