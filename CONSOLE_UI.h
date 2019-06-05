/*
 * UI�� ������ Ŭ����
 */
#pragma once
#ifndef __CONSOLE_UI_H
#define __CONSOLE_UI_H

#include <Windows.h>	// HANDLE, CONSOLE_CURSOR_INFO, COORD
#include <conio.h>		// _getch() : ���۸� �Է¹ް� ������� �ʴ� �Լ�
#include <string>
#include <vector>
#include "SUBJECT.h"
#include "MAKING_CHART.h"


#define ARROW 224	// ����Ű ù ��° ��
#define UP 72		// ����Ű ���� �� ���� ��
#define DOWN 80		// ����Ű �Ʒ��� �� ��° ��
#define LEFT 75		// ����Ű ���� �� ��° ��
#define RIGHT 77	// ����Ű ������ �� ��° ��
#define ENTER 13	// ���� ��
#define SPACE 32	// �����̽� ��
#define BACK 8		// backspace ��
#define ESC 27		// ESC ��

#define KEY_I_L 73	// i �빮�� ��
#define KEY_I_S 105	// i �ҹ��� ��
#define KEY_Y_L 89	// Y �빮�� ��
#define KEY_Y_S 121	// Y �ҹ��� ��
#define KEY_N_L 78	// N �빮�� ��
#define KEY_N_S 110	// N �ҹ��� ��

#define STD_TITLE_Y 10		// ������ ǥ���ϴµ� ǥ���� �Ǵ� y��
#define STD_MENU_X 50		// �޴��� ǥ���ϴµ� ǥ���� �Ǵ� x��
#define STD_MENU_Y 30		// �޴��� ǥ���ϴµ� ǥ���� �Ǵ� y��

#define MAX_LIST_SIZE 20	// ���� ����� �ִ� ũ��
#define LECTURE_DVIVISION 9	// ���� ��Ȱ ����

#define GRADE_X 2				// �г��� ǥ����µ� ǥ���� �Ǵ� x��
#define SORTATION_X	14			// ���������� ǥ���ϴµ� ǥ���� �Ǵ� X��
#define LECTURE_NAME_X	30		// ��������� ǥ���ϴµ� ǥ���� �Ǵ� X��
#define LECTURE_NUMBER_X 44		// ������ȣ�� ǥ���ϴµ� ǥ���� �Ǵ� X��
#define TIME_X	60				// �����ð��� ǥ���ϴµ� ǥ���� �Ǵ� X��
#define CLASS_POINT	72			// ������ ǥ���ϴµ� ǥ���� �Ǵ� X��
#define PHD_X 84				// �������� ǥ���ϴµ� ǥ���� �Ǵ� X��
#define TIME_DATA_X	93			// �ð� �� ������ ǥ���ϴµ� ǥ���� �Ǵ� X��
#define ROOM_X	111				// ���ǽ��� ǥ���ϴµ� ǥ���� �Ǵ� X��
#define STD_LECTURE_Y 14		// ���� ����� ǥ���ϴµ� ǥ���� �Ǵ� y��

#define INPUT_ERROR	1000		// �Է� ���� �ڵ�
#define CLASS_POINT_ERROR 1001	// ���� ���� �ڵ�
#define OVERLAP_LECTURE 1002	// ���� �ߺ�

class CONSOLE_UI
{
private:
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO console_cursor;
	COORD pos;

	std::string title;						// �ش� â�� ������ ����
	std::vector<std::string> menu_list;		// �ش� â�� �޴�

	std::string lecture_list[MAX_LIST_SIZE][LECTURE_DVIVISION];		// ���� ����� �����ϴ� 2���� �迭
	int page;

	SUBJECT subject;

public:
	// �⺻ �޼���
	CONSOLE_UI() { Set_Console_Info(); Set_Page(1); }
	~CONSOLE_UI();

	void Set_Title(std::string title) { this->title = title; }
	std::string Get_Title() { return title; }

	// menu_list�� ���� ����� ������ ��ȯ
	int Get_Menu_List_Size() { return menu_list.size(); }

	void Set_Page(int page) { this->page = page; }
	int Get_Page() { return page; }



	/**
	 * �ܼ�â�� ũ��� ���α׷� �̸��� �����ϴ� �޼���
	 * cols = 120 / lines = 50
	 * �ð�ǥ ����
	 */
	void Set_Console_Info();

	/**
	 * �ܼ�â Ŀ���� ǥ�� ����, �β��� �����ϴ� �޼���
	 * �Ű����� : dwSize = Ŀ�� ������ / bVisible = ǥ�� ����
	 */
	void Set_Cursor_Info(int dwSize, int bVisible);

	/**
	 * �ܼ�â Ŀ���� ��ǥ �����ϴ� �޼���
	 * �Ű����� : x = lines, y = cols
	 */
	void Set_Cursor_XY(int x, int y);

	/**
	 * menu_list�� ������ �ε����� ���� �����ϴ� �޼���
	 */
	void Insert_Menu(std::string menu_name);

	/**
	 * menu_list�� ������ �ε����� ���� �����ϴ� �޼���
	 */
	void delete_Menu() { menu_list.pop_back(); }

	/**
	 * �ش� �ε����� �޴� ����� ��ȯ�ϴ� �޼���
	 * Menu_Display���� �̿��ϴ� �޼���
	 * �Ű����� : index = menu_list�� ��� �ε���
	 */
	std::string Get_Menu_Item(int index) { return menu_list.at(index); }

	/**
	 * â�� ������ ����ϴ� �޼���
	 * �Ű����� : x = ���� ����� x��
	 */
	void Title_Display(int x);

	/**
	 * �޴� ����� ȭ�鿡 ����ϴ� �޼���
	 */
	void Menu_Display();

	/**
	 * �޴� ����� ȭ�鿡 ����ϴ� �޼���
	 * �Ű����� : x = ǥ���� �� x��, y = ǥ���� �� y��
	 */
	void Menu_Display(int x, int y);

	/*
	 * �޴��� ����Ű�� ȭ��ǥ�� �����ϴ� �޼���
	 */
	int Control_Arrow();

	/**
	 * ���� ���� (�г�/��������/�����/�����/.. ��) ����ϴ� �޼���
	 */
	void Lecture_Division_Display();

	/**
	 * ���� ����� ����ϴ� �޼���
	 */
	void Lecture_List_Display(MAKING_CHART *making_chart, SUBJECT *subject, std::string file_name, int grade);

	/*
	 * ���Ǹ� �����ϰ� �޼���
	 * �Ű����� : bVisible = Ŀ�� ǥ��
	 */
	void Choose_Lecture(MAKING_CHART *making_chart);

	/*
	 * ����ڰ� �Է��� ������ȣ�� ���� �ִ� row �ε����� ã�´�.
	 */
	int Check_Lecture_Number(std::string lecture_number);

	/**
	 * ������ �����ִ� �޼���
	 */
	void Class_Point_Display(MAKING_CHART* marking_chart);

	/**
	 * ������ ����ϴ� �޼���
	 */
	void Error_Display(int error_code);
};
#endif // !__CONSOLE_UI_H

