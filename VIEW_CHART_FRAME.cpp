#include "VIEW_CHART_FRAME.h"

void VIEW_CHART_FRAME::Set_Frame()
{
}

void VIEW_CHART_FRAME::Frame_Display()
{
}

void VIEW_CHART_FRAME::Frame_Display(MAKING_CHART* making_chart)
{
	system("cls");
	Explan_Display();
	console_ui.Class_Point_Display(making_chart);
	Chart_Display(making_chart);
}

void VIEW_CHART_FRAME::Explan_Display()
{
	int x = 38;
	int y = 5;

	console_ui.Set_Cursor_XY(x, y++);
	cout << "������ : SPACE / ENTER / BACK�� �����ּ���.";
	console_ui.Set_Cursor_XY(x, y++);
	cout << "�����ϱ� : Y�� �����ּ���. ";
}

void VIEW_CHART_FRAME::Chart_Display(MAKING_CHART* making_chart)
{
	while (1)
	{
		making_chart->Get_TimeTable(chart_table);

		int y = 10;
		console_ui.Set_Cursor_XY(MON_X, y++);
		cout << "��\t\tȭ\t\t��\t\t��\t\t��";

		for (int row = 1; row < MAX_ROWS_SIZE; row++)
		{	
			for (int col = 0; col < MAX_COLS_SIZE; col++)
			{
				switch (col)
				{
				//������
				case 2:
					console_ui.Set_Cursor_XY(MON_X, y);
					cout << chart_table[row][col];
					break;

				//������
				case 3:
					console_ui.Set_Cursor_XY(TUE_X, y);
					cout << chart_table[row][col];
					break;

				//������
				case 4:
					console_ui.Set_Cursor_XY(WED_X, y);
					cout << chart_table[row][col];
					break;

				//������
				case 5:
					console_ui.Set_Cursor_XY(THR_X, y);
					cout << chart_table[row][col];
					break;

				//������
				case 6:
					console_ui.Set_Cursor_XY(FRI_X, y);
					cout << chart_table[row][col];
					break;

				default:
					console_ui.Set_Cursor_XY(MON_X-20, y);
					cout << chart_table[row][col];
					break;
				}
			}
			y++;
		}
		
		int input_key = _getch();
		switch (input_key)
		{
		case KEY_Y_L:
		case KEY_Y_S:
			making_chart->arr_to_csv(VIEW_CHART);
			continue;

		case SPACE:
		case ENTER:
		case BACK:
			break;

		default:
			continue;
		}

		break;
	}
}
