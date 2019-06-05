#include "CONSOLE_UI.h"
#include <iostream>

using namespace std;

CONSOLE_UI::~CONSOLE_UI()
{
}

void CONSOLE_UI::Set_Console_Info()
{
	system("mode con cols=120 lines=50");
	system("title 시간표 제작");

	Set_Cursor_Info(1, 0);
}

void CONSOLE_UI::Set_Cursor_Info(int dwSize, int bVisible)
{
	console_cursor.bVisible = bVisible;
	console_cursor.dwSize = dwSize;

	SetConsoleCursorInfo(console_handle, &console_cursor);
}

void CONSOLE_UI::Set_Cursor_XY(int x, int y)
{
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(console_handle, pos);
}

void CONSOLE_UI::Insert_Menu(std::string menu_name)
{
	menu_list.push_back(menu_name);
}

void CONSOLE_UI::Title_Display(int x)
{
	Set_Cursor_XY(x, STD_TITLE_Y);
	cout << Get_Title();
}

void CONSOLE_UI::Menu_Display()
{
	for (int i = 0; i < Get_Menu_List_Size(); i++)
	{
		Set_Cursor_XY(STD_MENU_X, STD_MENU_Y + i * 2);
		cout << Get_Menu_Item(i);
	}
}

void CONSOLE_UI::Menu_Display(int x, int y)
{
	for (int i = 0; i < Get_Menu_List_Size(); i++)
	{
		Set_Cursor_XY(x, y++);
		cout << Get_Menu_Item(i);
	}
}

int CONSOLE_UI::Control_Arrow()
{
	int arrow_x = STD_MENU_X - 2;
	int arrow_y = STD_MENU_Y;

	Set_Cursor_XY(arrow_x, arrow_y);
	cout << ">";

	while (1)
	{
		// 방향키의 값은 2개, 첫 번째 값은 항상 똑같다
		int input_key_value = _getch();

		if (input_key_value == ARROW)
		{
			// 첫 번째 값이 아닌 다른 값을 이어 받는다
			input_key_value = _getch();

			switch (input_key_value)
			{
				// 위와 왼쪽을 눌렀을 때
			case UP:
			case LEFT:
				// 현재 화살표의 y값이 맨 위일 때
				if (arrow_y == STD_MENU_Y)
				{
					Set_Cursor_XY(arrow_x, arrow_y);
					cout << " ";
					arrow_y = STD_MENU_Y + (Get_Menu_List_Size() - 1) * 2;

					Set_Cursor_XY(arrow_x, arrow_y);
					cout << ">";
				}

				else
				{
					Set_Cursor_XY(arrow_x, arrow_y);
					cout << " ";
					arrow_y -= 2;

					Set_Cursor_XY(arrow_x, arrow_y);
					cout << ">";
				}
				break;

				// 아래와 오른쪽을 눌렀을 때
			case DOWN:
			case RIGHT:
				if (arrow_y == STD_MENU_Y + (Get_Menu_List_Size() - 1) * 2)
				{
					Set_Cursor_XY(arrow_x, arrow_y);
					cout << " ";
					arrow_y = STD_MENU_Y;

					Set_Cursor_XY(arrow_x, arrow_y);
					cout << ">";
				}

				else
				{
					Set_Cursor_XY(arrow_x, arrow_y);
					cout << " ";
					arrow_y += 2;

					Set_Cursor_XY(arrow_x, arrow_y);
					cout << ">";
				}

				break;
			}
		}

		else if (input_key_value == SPACE || input_key_value == ENTER)
		{
			return arrow_y;
		}

		else if (input_key_value == BACK)
			return BACK;
	}
}

void CONSOLE_UI::Lecture_Division_Display()
{
	Set_Cursor_XY(GRADE_X, STD_LECTURE_Y);
	cout << "학년        교과구분        과목명        수강번호        시간        학점        교수명        시간         강의실";
}

void CONSOLE_UI::Lecture_List_Display(MAKING_CHART* making_chart, SUBJECT* subject, string file_name, int grade)
{
	// 강의 목록을 배열에 받아온다.
	subject->Send_Division_Lecture_Information(file_name, page, grade, lecture_list);

	// 최대 페이지 수를 구한다.
	int max_page = (subject->Get_Grades_Size(grade) / MAX_LIST_SIZE);
	if ((subject->Get_Grades_Size(grade) % MAX_LIST_SIZE) != 0)
		max_page++;

	while (1)
	{
		system("cls");

		Class_Point_Display(making_chart);
		Lecture_Division_Display();

		int y = STD_LECTURE_Y + 2;
		for (int row = 0; row < MAX_LIST_SIZE; row++)
		{
			for (int col = 0; col < LECTURE_DVIVISION; col++)
			{
				switch (col)
				{
				// 학년
				case 0:
					Set_Cursor_XY(GRADE_X, y);
					cout << lecture_list[row][col];
					break;

				// 교과구분
				case 1:
					Set_Cursor_XY(SORTATION_X, y);
					cout << lecture_list[row][col];
					break;

				// 과목명
				case 2:
					Set_Cursor_XY(LECTURE_NAME_X, y);
					cout << lecture_list[row][col];
					break;

				// 수강번호
				case 3:
					Set_Cursor_XY(LECTURE_NUMBER_X, y);
					cout << lecture_list[row][col] <<  "          ";
					break;

				// 시간
				case 4:
					Set_Cursor_XY(TIME_X, y);
					cout << lecture_list[row][col]<<"        ";
					break;

				// 학점
				case 5:
					Set_Cursor_XY(CLASS_POINT, y);
					cout << lecture_list[row][col];
					break;

				// 교수명
				case 6:
					Set_Cursor_XY(PHD_X, y);
					cout << lecture_list[row][col];
					break;

				// 수업 및 요일
				case 7:
					Set_Cursor_XY(TIME_DATA_X, y);
					cout << lecture_list[row][col];
					break;

				// 강의실
				case 8:
					Set_Cursor_XY(ROOM_X, y);
					cout << lecture_list[row][col];
					break;

				default:
					break;
				}
				if (col == 5)
					cout << "    ";
			}
			y++;
		}

		Set_Cursor_XY(40, 38);
		cout << "수강번호를 입력하려면 i를 눌러주세요.";

		int input_key_value = _getch();

		if (input_key_value == ARROW)
		{
			input_key_value = _getch();

			switch (input_key_value)
			{
			case LEFT:
				if (page > 1)
				{
					page--;
					subject->Send_Division_Lecture_Information(file_name, page, grade, lecture_list);

				}
				break;

			case RIGHT:
				if (page < max_page)
				{
					page++;
					subject->Send_Division_Lecture_Information(file_name, page, grade, lecture_list);
				}
				break;
			}

		}

		else if (input_key_value == KEY_I_L || input_key_value == KEY_I_S)
		{
			Choose_Lecture(making_chart);
			continue;
		}

		else if (input_key_value == BACK)
		{
			subject->Read_File_Close();
			break;
		}

		else
		{

		}
	}
}

void CONSOLE_UI::Choose_Lecture(MAKING_CHART* making_chart)
{
	Set_Cursor_XY(40, 40);
	Set_Cursor_Info(1, 1);

	string lecture_number;
	cin >> lecture_number;

	// 선택한 강의가 인덱스에 있는지 확인
	int index = Check_Lecture_Number(lecture_number);
	if (index != -1)
	{
		// 현재 학점이 19점인지 확인
		if (making_chart->Is_Full_Class_Point())
			Error_Display(CLASS_POINT_ERROR);

		// 학점을 추가했을 때 19학점이상이 아니면 추가
		if (making_chart->Add_Class_Point(lecture_list[index]))
		{
			int overlap = making_chart->fill_time(lecture_list[index]);
			if (overlap == 1)
			{
				making_chart->Sub_Class_Point(lecture_list[index]);
				Error_Display(OVERLAP_LECTURE);
			}
		}

		else
			Error_Display(CLASS_POINT_ERROR);

		Set_Cursor_Info(1, 0);
	}

	else
		Error_Display(INPUT_ERROR);
}

int CONSOLE_UI::Check_Lecture_Number(string lecture_number)
{
	for (int index = 0; index < MAX_LIST_SIZE; index++)
	{
		// 일치하는 수강번호를 찾으면 해당 인덱스 반환
		 if (lecture_list[index][3] == lecture_number)
			return index;
	}

	return -1;
}

void CONSOLE_UI::Class_Point_Display(MAKING_CHART* marking_chart)
{
	Set_Cursor_XY(98, 4);
	cout << "현재 학점 : " << marking_chart->Get_Class_Point();
}

void CONSOLE_UI::Error_Display(int error_code)
{
	system("cls");
	Set_Cursor_Info(1, 0);

	switch (error_code)
	{
	case INPUT_ERROR:
		Set_Cursor_XY(50, 15);
		cout << "잘못된 값이 입력됬습니다.";
		break;

	case CLASS_POINT_ERROR:
		Set_Cursor_XY(45, 15);
		cout << "최대학점 이상입니다. 다시 입력해주세요.";
		break;

	case OVERLAP_LECTURE:
		Set_Cursor_XY(45, 15);
		cout << "시간이 중복됩니다 다시 선택해주세요.";
		break;

	default:
		break;
	}

	Set_Cursor_XY(47, 40);
	cout << "돌아가려면 아무 키나 입력하세요.";

	while (1)
	{
		int input_key_value = _getch();
		if (input_key_value != 0)
			break;
	}
}

