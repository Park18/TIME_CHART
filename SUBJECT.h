#pragma once
#ifndef __SUBJECT_H
#define __SUBJECT_H

#include <iostream>	
#include <fstream>
#include <vector>

#define MAX_LIST_SIZE 20	// �ֿܼ� ǥ���� ������ �ִ� ����
#define LECTURE_DVIVISION 9	// ���� ��Ȱ ����

class SUBJECT
{
private:
	std::ifstream read_file;

	std::vector<std::string> grade_1;		// 1�г�
	std::vector<std::string> grade_2;		// 2�г�
	std::vector<std::string> grade_3;		// 3�г�
	std::vector<std::string> grade_4;		// 4�г�
	std::vector<std::string> grade_public;	// ��ü�г�
	std::vector<std::string> grade_all;		// �г� ��ü

	int grade_1_size;		// 1�г� ���� ��� ����
	int grade_2_size;		// 2�г� ���� ��� ����
	int grade_3_size;		// 3�г� ���� ��� ����
	int grade_4_size;		// 4�г� ���� ��� ����
	int grade_public_size;	// ��ü�г� ���� ��� ����
	int grade_all_size;		// ��� ���� ��� ����

public:
	SUBJECT();

	/**
	 * �г� ���� ��� ������ �����ϴ� �޼���
	 */
	void Set_Grade_1_Size(int grade_1_size) { this->grade_1_size = grade_1_size; }
	void Set_Grade_2_Size(int grade_2_size) { this->grade_2_size = grade_2_size; }
	void Set_Grade_3_Size(int grade_3_size) { this->grade_3_size = grade_3_size; }
	void Set_Grade_4_Size(int grade_4_size) { this->grade_4_size = grade_4_size; }
	void Set_Grade_Public_Size(int grade_public_size) { this->grade_public_size = grade_public_size; }
	void Set_Grade_All_Size(int grade_all_size) { this->grade_all_size = grade_all_size; }

	/**
	 * �г� ���� ��� ������ ��ȯ�ϴ� �޼���
	 */
	int Get_Grade_1_Size() { return grade_1_size; }
	int Get_Grade_2_Size() { return grade_2_size; }
	int Get_Grade_3_Size() { return grade_3_size; }
	int Get_Grade_4_Size() { return grade_4_size; }
	int Get_Grade_Public_Size() { return grade_public_size; }
	int Get_Grade_All_Size() { return grade_all_size; }

	/**
	 * �� ������ ����ȵ� ���ǵ��� ����� ������ �����ϴ� �޼���
	 */
	void Set_Grades_Size(int grade);

	/**
	 * �䱸�� �г� ���� ����� ������ ��ȯ�ϴ� �޼���
	 * �Ű����� : grade = ��û�� �г�
		* 1 = 1�г�
		* 2 = 2�г�
		* 3 = 3�г�
		* 4 = 4�г�
		* 5 = ��ü�г�(����г��� ���� �� �ִ�...)
		* 6 = ����г�(1, 2, 3, 4, ��ü�г�)
	 */
	int Get_Grades_Size(int grade);

	/**
	 *	���� ����/�ݴ� �޼���
	 */
	void Read_File_Open(std::string file_name) { read_file.open(file_name); }
	void Read_File_Close() { read_file.close(); }

	/**
	 * ���� ������ ��� ���͵��� ��Ҹ� �ʱ�ȭ�ϴ� �޼���
	 */
	void Clear_Grade_List();

	/**
	 * ���� ����� ����� csv������ �д� �޼���
	 * �Ű����� : file_name = ���� ������ �̸�
	 */
	void Read_Lecture_List(std::string file_name);

	/**
	 * �ֿܼ� ǥ���� ����Ʈ�� ũ�⺸�� ������ �� ������ �߰����ִ� �޼���
	 * �Ű����� : grade = �г� ���� ��� ����Ʈ
	 */
	void Padding_Data(std::vector<std::string>* grade);

	/**
	 * �� ���� string���� ������ ���� ������ 9���� ������ �������ִ� �޼���
	 * �Ű�����
		* origin_lecture_information = ���� ���� ����
		* array_lecture_information = ��Ȱ�� ������ ���� �迭
	 */
	void Divide_Lecture_List(std::string origin_lecture_information, std::string array_lecture_information[]);

	/**
	 * ȭ�鿡 ����ϱ� ���� �ӽ� ������� �迭�� �־��ִ� �޼���
	 *	�Ű�����
		*sender = ���� ������ ��û�� �迭, receiver = ���� ������ ��û�� �迭
		* [0]grade			= �г�
		* [1]sortation		= ��������
		* [2]lecture_name	= �������
		* [3]lecture_number	= ������ȣ
		* [4]time			= �����ð�
		* [5]credit			= ����
		* [6]phD			= ������
		* [7]time_data		= �ð� �� ����
		* [8]room			= ���ǽ�
	 */
	void Send_Lecture_Information(std::string sender[], std::string receiver[]);

	/**
	 * ������ strimg���� ������ ���� ������ 9���� ������ ȭ�鿡 ǥ�õ� 2�����迭�� �����ϴ� �޼���
	 * �Ű�����
		* file_name = ���� ���� �̸�
		* page = ���� ������
		* grade = ���� �г�
		* ȭ�鿡 ǥ���� 2���� �迭
	 */
	void Send_Division_Lecture_Information(std::string file_name, int page, int grade, std::string lecture_list[][9]);
};


#endif // !__SUBJECT_H

