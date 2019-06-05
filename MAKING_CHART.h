#pragma once
#ifndef __MAKING_CHART_H
#define __MAKING_CHART_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#define BASE_CHART "DB/base.csv"
#define MAX_CLASS_POINT 19		// 최대 학점

using namespace std;

class MAKING_CHART
{
private:
	enum { MONDAY = 2, TUESDAY = 3, WEDNESDAY = 4, THURSDAY = 5, FRIDAY = 6 };

	vector< vector<string> > vector_time_table;
	vector<string> token_vector;
	string line;
	ifstream fin; // base.csv파일 열기
	ofstream fout; // 결과물.csv 파일 만들기
	string TimeTable[19][7]; // 결과물.csv 파일에 넣을 배열

	int class_point;

	/*
	 * string을 delimiter에 따라서 토큰화해서 vector배열에 넣어주는 함수.
	 * vector배열을 return 한다.
	 */
	vector<string> tokenize_getline(const string& data, const char delimiter);

public:
	MAKING_CHART();
	~MAKING_CHART();

	void Set_Class_Point(int class_point) { this->class_point = class_point; }
	int Get_Class_Point() { return class_point; }

	/**
	 * 학점을 더하는 메서드
	 */
	int Add_Class_Point(string data[]);

	/**
	 * 학점을 빼는 클래스
	 */
	void Sub_Class_Point(string data[]);

	/**
	 * 19학점 이상인지 검사하는 메서드
	 */
	int Is_Full_Class_Point();


	/**
	 * TimeTable을 복사해주는 메서드
	 * 매개변수 : time_table = 복사해서 넣을 배열
	 */
	void Get_TimeTable(string time_table[][7]);

	/*
	 * base.csv파일을 읽어서 TimeTable배열에 복사해주는 함수.
	 */
	void read_base_to_arr(string address);

	/*
	 * TimeTalbe배열을 읽어서 결과물을 만들고 매개변수 address주소에 파일 생성해주는 함수.
	 */
	void arr_to_csv(string address);

	/*
	 * 복사된 TimeTable배열에 수업시간에 따라 채워 넣어주는 함수.
	 */
	int fill_time(string* INPUT);

};
#endif // !__MAKING_CHART_H