#include "START_FRAME.h"

START_FRAME::START_FRAME()
{
	Set_Frame();
}

void START_FRAME::Set_Frame()
{
	console_ui.Set_Title("�� �� ǥ �� �� �� ��");

	console_ui.Insert_Menu("�� �� ǥ �� ��");
	console_ui.Insert_Menu("�� �� ǥ �� ȸ");
	console_ui.Insert_Menu("��          ��");
	console_ui.Insert_Menu("��          ��");

	making_chart.read_base_to_arr(BASE_CHART);		// �⺻ �ð�ǥ������ �д� �޼���
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
		case STD_MENU_Y:		// �ð�ǥ ����
			making_frame.Frame_Display(&making_chart);
			break;

		case STD_MENU_Y + 2:	// �ð�ǥ ��ȸ
			view_chart_frame.Frame_Display(&making_chart);
			break;

		case STD_MENU_Y + 4:	// ����
			explan_frame.Frame_Display();
			break;

		case STD_MENU_Y + 6:	// ����
			exit(0);
		}
	}
}

void START_FRAME::Frame_Display(MAKING_CHART* making_chart)
{
}
