#include "EXPLAN_FRAME.h"
#include <iostream>

using namespace std;

EXPLAN_FRAME::EXPLAN_FRAME()
{
	Set_Frame();
}

void EXPLAN_FRAME::Set_Frame()
{
	console_ui.Set_Title("������ : SPACE / ENTER / BACK�� �����ּ���.");

	console_ui.Insert_Menu("�� ���α׷��� �ð�ǥ�� csv���� �������� �������ִ� ���α׷� �Դϴ�.");
	console_ui.Insert_Menu("�߸��� �Է°����� ���� ������ å������ �ʽ��ϴ�.");
	console_ui.Insert_Menu("");
	console_ui.Insert_Menu("����");
	console_ui.Insert_Menu("Ŀ�� �̵� : ����Ű");
	console_ui.Insert_Menu("�ڷΰ��� : �齺���̽�");
	console_ui.Insert_Menu("�ð�ǥ �����ϱ� : �ð�ǥ ��ȸ -> Y �Է�");
	console_ui.Insert_Menu("�ð�ǥ ���� ��� : TIME_CHART/TIME_CHART.csv");
}

void EXPLAN_FRAME::Frame_Display()
{
	Explan_Display();
}

void EXPLAN_FRAME::Frame_Display(MAKING_CHART* making_chart)
{
}

void EXPLAN_FRAME::Explan_Display()
{
	system("cls");
	
	while (1)
	{
		console_ui.Title_Display(38);
		console_ui.Menu_Display(30, 16);

		int input_key_value = _getch();
		switch (input_key_value)
		{
		case BACK:
		case ENTER:
		case SPACE:
			break;

		default:
			continue;
		}

		break;
	}
}
