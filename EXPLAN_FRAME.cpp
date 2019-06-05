#include "EXPLAN_FRAME.h"
#include <iostream>

using namespace std;

EXPLAN_FRAME::EXPLAN_FRAME()
{
	Set_Frame();
}

void EXPLAN_FRAME::Set_Frame()
{
	console_ui.Set_Title("나가기 : SPACE / ENTER / BACK을 눌러주세요.");

	console_ui.Insert_Menu("본 프로그램은 시간표를 csv파일 포맷으로 제작해주는 프로그램 입니다.");
	console_ui.Insert_Menu("잘못된 입력값으로 인한 오류는 책임지지 않습니다.");
	console_ui.Insert_Menu("");
	console_ui.Insert_Menu("사용법");
	console_ui.Insert_Menu("커서 이동 : 방향키");
	console_ui.Insert_Menu("뒤로가기 : 백스페이스");
	console_ui.Insert_Menu("시간표 저장하기 : 시간표 조회 -> Y 입력");
	console_ui.Insert_Menu("시간표 저장 장소 : TIME_CHART/TIME_CHART.csv");
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
