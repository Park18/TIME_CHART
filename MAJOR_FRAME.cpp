#include "MAJOR_FRAME.h"


MAJOR_FRAME::MAJOR_FRAME()
{
	Set_Frame();
}

void MAJOR_FRAME::Set_Frame()
{
	console_ui.Set_Title("��� ���� ����");

	console_ui.Insert_Menu("1     ��    ��");
	console_ui.Insert_Menu("2     ��    ��");
	console_ui.Insert_Menu("3     ��    ��");
	console_ui.Insert_Menu("4     ��    ��");
	console_ui.Insert_Menu("��          ü");
	console_ui.Insert_Menu("��    ��    ��");
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
		case STD_MENU_Y:		// 1�г�
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 1);
			continue;

		case STD_MENU_Y + 2:	// 2�г�
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 2);
			continue;

		case STD_MENU_Y + 4:	// 3�г�
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 3);
			continue;

		case STD_MENU_Y + 6:	// 4�г�
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 4);
			continue;

		case STD_MENU_Y + 8:	// ��ü
			console_ui.Lecture_List_Display(making_chart, &major, SECURITY_INFORMATION, 6);
			continue;

		case STD_MENU_Y + 10:	// ������
			break;
		}

		break;
	}
}
