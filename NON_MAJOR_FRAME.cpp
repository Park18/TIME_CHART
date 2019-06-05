#include "NON_MAJOR_FRAME.h"

NON_MAJOR_FRAME::NON_MAJOR_FRAME()
{
	Set_Frame();
}

void NON_MAJOR_FRAME::Set_Frame()
{
	console_ui.Set_Title("��� ���� ����");

	console_ui.Insert_Menu("��          ��");
	console_ui.Insert_Menu("��          ��");
	console_ui.Insert_Menu("��    ��    ��");
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
		case STD_MENU_Y:		// ����
			console_ui.Lecture_List_Display(making_chart, &non_major, PUBLIC, 6);
			continue;

		case STD_MENU_Y + 2:	// �Ϲ�
			console_ui.Lecture_List_Display(making_chart, &non_major, NORMAL, 6);
			continue;

		case STD_MENU_Y + 4:	// ������
		case BACK:
			break;
		}

		break;
	}
}
