#include "VIRTUAL_CLASS_FRAME.h"

VIRTUAL_CLASS_FRAME::VIRTUAL_CLASS_FRAME()
{
	Set_Frame();
}

void VIRTUAL_CLASS_FRAME::Set_Frame()
{
	console_ui.Set_Title("��� ���� ����");

	console_ui.Insert_Menu("��  ��  ��  ��");
	console_ui.Insert_Menu("O      C     U");
	console_ui.Insert_Menu("��    ��    ��");
}

void VIRTUAL_CLASS_FRAME::Frame_Display()
{
}

void VIRTUAL_CLASS_FRAME::Frame_Display(MAKING_CHART* making_chart)
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
		case STD_MENU_Y:		// �г�����
			console_ui.Lecture_List_Display(making_chart, &virtual_class, VIRTUAL, 6);
			continue;

		case STD_MENU_Y + 2:	// OCU
			console_ui.Lecture_List_Display(making_chart, &virtual_class, OCU, 6);
			continue;

		case STD_MENU_Y + 4:	// ������
		case BACK:
			break;
		}

		break;
	}
}
