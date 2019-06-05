#pragma once
#ifndef __MAKING_CHART_H
#define __MAKING_CHART_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#define BASE_CHART "DB/base.csv"
#define MAX_CLASS_POINT 19		// �ִ� ����

using namespace std;

class MAKING_CHART
{
private:
	enum { MONDAY = 2, TUESDAY = 3, WEDNESDAY = 4, THURSDAY = 5, FRIDAY = 6 };

	vector< vector<string> > vector_time_table;
	vector<string> token_vector;
	string line;
	ifstream fin; // base.csv���� ����
	ofstream fout; // �����.csv ���� �����
	string TimeTable[19][7]; // �����.csv ���Ͽ� ���� �迭

	int class_point;

	/*
	 * string�� delimiter�� ���� ��ūȭ�ؼ� vector�迭�� �־��ִ� �Լ�.
	 * vector�迭�� return �Ѵ�.
	 */
	vector<string> tokenize_getline(const string& data, const char delimiter);

public:
	MAKING_CHART();
	~MAKING_CHART();

	void Set_Class_Point(int class_point) { this->class_point = class_point; }
	int Get_Class_Point() { return class_point; }

	/**
	 * ������ ���ϴ� �޼���
	 */
	int Add_Class_Point(string data[]);

	/**
	 * ������ ���� Ŭ����
	 */
	void Sub_Class_Point(string data[]);

	/**
	 * 19���� �̻����� �˻��ϴ� �޼���
	 */
	int Is_Full_Class_Point();


	/**
	 * TimeTable�� �������ִ� �޼���
	 * �Ű����� : time_table = �����ؼ� ���� �迭
	 */
	void Get_TimeTable(string time_table[][7]);

	/*
	 * base.csv������ �о TimeTable�迭�� �������ִ� �Լ�.
	 */
	void read_base_to_arr(string address);

	/*
	 * TimeTalbe�迭�� �о ������� ����� �Ű����� address�ּҿ� ���� �������ִ� �Լ�.
	 */
	void arr_to_csv(string address);

	/*
	 * ����� TimeTable�迭�� �����ð��� ���� ä�� �־��ִ� �Լ�.
	 */
	int fill_time(string* INPUT);

};
#endif // !__MAKING_CHART_H