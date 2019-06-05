#include "MAKING_FRAME.h"

MAKING_FRAME::MAKING_FRAME()
{
	Set_Frame();
}

void MAKING_FRAME::Set_Frame()
{
	console_ui.Set_Title("�о� ����");

	console_ui.Insert_Menu("��          ��");
	console_ui.Insert_Menu("��          ��");
	console_ui.Insert_Menu("��          ��");
	console_ui.Insert_Menu("��    ��    ��");
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
		case STD_MENU_Y:		// ����
			major_frame.Frame_Display(making_chart);
			continue;

		case STD_MENU_Y + 2:	// ����
			non_major_frame.Frame_Display(making_chart);
			continue;

		case STD_MENU_Y + 4:	// ����
			virtual_class_frame.Frame_Display(making_chart);
			continue;

		case STD_MENU_Y + 6:	// ������
		case BACK:
			break;
		}

		break;
	}
}
