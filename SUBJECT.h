#pragma once
#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <iostream>	
#include <fstream>
#include <vector>

#define MAX_LIST_SIZE 20	// 콘솔에 표시할 강의의 최대 개수
#define LECTURE_DVIVISION 9	// 강의 분활 개수

class SUBJECT
{
private:
	std::ifstream read_file;

	std::vector<std::string> grade_1;		// 1학년
	std::vector<std::string> grade_2;		// 2학년
	std::vector<std::string> grade_3;		// 3학년
	std::vector<std::string> grade_4;		// 4학년
	std::vector<std::string> grade_public;	// 전체학년
	std::vector<std::string> grade_all;		// 학년 전체

	int grade_1_size;		// 1학년 강의 목록 개수
	int grade_2_size;		// 2학년 강의 목록 개수
	int grade_3_size;		// 3학년 강의 목록 개수
	int grade_4_size;		// 4학년 강의 목록 개수
	int grade_public_size;	// 전체학년 강의 목록 개수
	int grade_all_size;		// 모든 강의 목록 개수

public:
	SUBJECT();

	/**
	 * 학년 강의 목록 개수를 설정하는 메서드
	 */
	void Set_Grade_1_Size(int grade_1_size) { this->grade_1_size = grade_1_size; }
	void Set_Grade_2_Size(int grade_2_size) { this->grade_2_size = grade_2_size; }
	void Set_Grade_3_Size(int grade_3_size) { this->grade_3_size = grade_3_size; }
	void Set_Grade_4_Size(int grade_4_size) { this->grade_4_size = grade_4_size; }
	void Set_Grade_Public_Size(int grade_public_size) { this->grade_public_size = grade_public_size; }
	void Set_Grade_All_Size(int grade_all_size) { this->grade_all_size = grade_all_size; }

	/**
	 * 학년 강의 목록 개수를 반환하는 메서드
	 */
	int Get_Grade_1_Size() { return grade_1_size; }
	int Get_Grade_2_Size() { return grade_2_size; }
	int Get_Grade_3_Size() { return grade_3_size; }
	int Get_Grade_4_Size() { return grade_4_size; }
	int Get_Grade_Public_Size() { return grade_public_size; }
	int Get_Grade_All_Size() { return grade_all_size; }

	/**
	 * 빈 공간이 저장안된 강의들의 목록의 개수를 설정하는 메서드
	 */
	void Set_Grades_Size(int grade);

	/**
	 * 요구된 학년 강의 목록의 개수를 반환하는 메서드
	 * 매개변수 : grade = 요청된 학년
		* 1 = 1학년
		* 2 = 2학년
		* 3 = 3학년
		* 4 = 4학년
		* 5 = 전체학년(모든학년이 들을 수 있는...)
		* 6 = 모든학년(1, 2, 3, 4, 전체학년)
	 */
	int Get_Grades_Size(int grade);

	/**
	 *	파일 열기/닫는 메서드
	 */
	void Read_File_Open(std::string file_name) { read_file.open(file_name); }
	void Read_File_Close() { read_file.close(); }

	/**
	 * 강의 정보를 담는 벡터들의 요소를 초기화하는 메서드
	 */
	void Clear_Grade_List();

	/**
	 * 강의 목록이 저장된 csv파일을 읽는 메서드
	 * 매개변수 : file_name = 읽을 파일의 이름
	 */
	void Read_Lecture_List(std::string file_name);

	/**
	 * 콘솔에 표기할 리스트의 크기보다 작으면 빈 정보를 추가해주는 메서드
	 * 매개변수 : grade = 학년 강의 목록 리스트
	 */
	void Padding_Data(std::vector<std::string>* grade);

	/**
	 * 한 줄의 string으로 구성된 강의 정보를 9개로 나누어 저장해주는 메서드
	 * 매개변수
		* origin_lecture_information = 원본 강의 정보
		* array_lecture_information = 분활된 정보를 넣을 배열
	 */
	void Divide_Lecture_List(std::string origin_lecture_information, std::string array_lecture_information[]);

	/**
	 * 화면에 출력하기 위한 임시 저장장소 배열에 넣어주는 메서드
	 *	매개변수
		*sender = 강의 정보를 요청한 배열, receiver = 강의 정보를 요청한 배열
		* [0]grade			= 학년
		* [1]sortation		= 교과구분
		* [2]lecture_name	= 교과목명
		* [3]lecture_number	= 수강번호
		* [4]time			= 수업시간
		* [5]credit			= 학점
		* [6]phD			= 교수명
		* [7]time_data		= 시간 및 요일
		* [8]room			= 강의실
	 */
	void Send_Lecture_Information(std::string sender[], std::string receiver[]);

	/**
	 * 한줄의 strimg으로 구성된 강의 정보를 9개로 나누고 화면에 표시될 2차원배열에 저장하는 메서드
	 * 매개변수
		* file_name = 읽을 파일 이름
		* page = 읽을 페이지
		* grade = 읽을 학년
		* 화면에 표시할 2차원 배열
	 */
	void Send_Division_Lecture_Information(std::string file_name, int page, int grade, std::string lecture_list[][9]);
};


#endif // !__SUBJECT_H

