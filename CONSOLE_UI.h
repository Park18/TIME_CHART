/*
 * UI에 관여된 클래스
 */
#pragma once
#ifndef __CONSOLE_UI_H
#define __CONSOLE_UI_H

#include <Windows.h>	// HANDLE, CONSOLE_CURSOR_INFO, COORD
#include <conio.h>		// _getch() : 버퍼를 입력받고 출력하지 않는 함수
#include <string>
#include <vector>
#include "SUBJECT.h"
#include "MAKING_CHART.h"


#define ARROW 224	// 방향키 첫 번째 값
#define UP 72		// 방향키 위쪽 두 번쟤 값
#define DOWN 80		// 방향키 아래쪽 두 번째 값
#define LEFT 75		// 방향키 왼쪽 두 번째 값
#define RIGHT 77	// 방향키 오른쪽 두 번째 값
#define ENTER 13	// 엔터 값
#define SPACE 32	// 스페이스 값
#define BACK 8		// backspace 값
#define ESC 27		// ESC 값

#define KEY_I_L 73	// i 대문자 값
#define KEY_I_S 105	// i 소문자 값
#define KEY_Y_L 89	// Y 대문자 값
#define KEY_Y_S 121	// Y 소문자 값
#define KEY_N_L 78	// N 대문자 값
#define KEY_N_S 110	// N 소문자 값

#define STD_TITLE_Y 10		// 제목을 표시하는데 표준이 되는 y값
#define STD_MENU_X 50		// 메뉴를 표시하는데 표준이 되는 x값
#define STD_MENU_Y 30		// 메뉴를 표시하는데 표준이 되는 y값

#define MAX_LIST_SIZE 20	// 강의 목록의 최대 크기
#define LECTURE_DVIVISION 9	// 강의 분활 개수

#define GRADE_X 2				// 학년을 표시헤는데 표준이 되는 x값
#define SORTATION_X	14			// 교과구분을 표시하는데 표준이 되는 X값
#define LECTURE_NAME_X	30		// 교과목명을 표시하는데 표준이 되는 X값
#define LECTURE_NUMBER_X 44		// 수강번호를 표시하는데 표준이 되는 X값
#define TIME_X	60				// 수업시간을 표시하는데 표준이 되는 X값
#define CLASS_POINT	72			// 학점을 표시하는데 표준이 되는 X값
#define PHD_X 84				// 교수명을 표시하는데 표준이 되는 X값
#define TIME_DATA_X	93			// 시간 및 요일을 표시하는데 표준이 되는 X값
#define ROOM_X	111				// 강의실을 표시하는데 표준이 되는 X값
#define STD_LECTURE_Y 14		// 강의 목록을 표시하는데 표준이 되는 y값

#define INPUT_ERROR	1000		// 입력 오류 코드
#define CLASS_POINT_ERROR 1001	// 학점 오류 코드
#define OVERLAP_LECTURE 1002	// 강의 중복

class CONSOLE_UI
{
private:
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO console_cursor;
	COORD pos;

	std::string title;						// 해당 창의 제목을 저장
	std::vector<std::string> menu_list;		// 해당 창의 메뉴

	std::string lecture_list[MAX_LIST_SIZE][LECTURE_DVIVISION];		// 강의 목록을 저장하는 2차원 배열
	int page;

	SUBJECT subject;

public:
	// 기본 메서드
	CONSOLE_UI() { Set_Console_Info(); Set_Page(1); }
	~CONSOLE_UI();

	void Set_Title(std::string title) { this->title = title; }
	std::string Get_Title() { return title; }

	// menu_list가 가진 요소의 개수를 반환
	int Get_Menu_List_Size() { return menu_list.size(); }

	void Set_Page(int page) { this->page = page; }
	int Get_Page() { return page; }



	/**
	 * 콘솔창의 크기와 프로그램 이름을 설정하는 메서드
	 * cols = 120 / lines = 50
	 * 시간표 제작
	 */
	void Set_Console_Info();

	/**
	 * 콘솔창 커서의 표시 유무, 두께를 설정하는 메서드
	 * 매개변수 : dwSize = 커서 사이즈 / bVisible = 표시 유무
	 */
	void Set_Cursor_Info(int dwSize, int bVisible);

	/**
	 * 콘솔창 커서의 좌표 설정하는 메서드
	 * 매개변수 : x = lines, y = cols
	 */
	void Set_Cursor_XY(int x, int y);

	/**
	 * menu_list의 마지막 인덱스에 값을 저장하는 메서드
	 */
	void Insert_Menu(std::string menu_name);

	/**
	 * menu_list의 마지막 인덱스의 값을 삭제하는 메서드
	 */
	void delete_Menu() { menu_list.pop_back(); }

	/**
	 * 해당 인덱스의 메뉴 목록을 반환하는 메서드
	 * Menu_Display에서 이용하는 메서드
	 * 매개변수 : index = menu_list의 요소 인덱스
	 */
	std::string Get_Menu_Item(int index) { return menu_list.at(index); }

	/**
	 * 창의 제목을 출력하는 메서드
	 * 매개변수 : x = 제목 출력의 x값
	 */
	void Title_Display(int x);

	/**
	 * 메뉴 목록을 화면에 출력하는 메서드
	 */
	void Menu_Display();

	/**
	 * 메뉴 목록을 화면에 출력하는 메서드
	 * 매개변수 : x = 표준이 될 x값, y = 표준이 될 y값
	 */
	void Menu_Display(int x, int y);

	/*
	 * 메뉴를 가리키는 화살표를 제어하는 메서드
	 */
	int Control_Arrow();

	/**
	 * 강의 구분 (학년/교과구분/영어강의/과목명/.. 등) 출력하는 메서드
	 */
	void Lecture_Division_Display();

	/**
	 * 강의 목록을 출력하는 메서드
	 */
	void Lecture_List_Display(MAKING_CHART *making_chart, SUBJECT *subject, std::string file_name, int grade);

	/*
	 * 강의를 선택하고 메서드
	 * 매개변수 : bVisible = 커서 표시
	 */
	void Choose_Lecture(MAKING_CHART *making_chart);

	/*
	 * 사용자가 입력한 수강번호를 갖고 있는 row 인덱스를 찾는다.
	 */
	int Check_Lecture_Number(std::string lecture_number);

	/**
	 * 학점을 보여주는 메서드
	 */
	void Class_Point_Display(MAKING_CHART* marking_chart);

	/**
	 * 에러를 출력하는 메서드
	 */
	void Error_Display(int error_code);
};
#endif // !__CONSOLE_UI_H

