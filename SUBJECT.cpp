#include "SUBJECT.h"
#include <iostream>
#include <string>

using namespace std;

SUBJECT::SUBJECT()
{
	Clear_Grade_List();
}

void SUBJECT::Set_Grades_Size(int grade)
{
	int size = 0;

	switch (grade)
	{
	case 1:
		for (int index = 0; index < grade_1.size(); index++)
		{
			if (grade_1.at(index) != "")
				size++;
		}

		Set_Grade_1_Size(size);
		break;

	case 2:
		for (int index = 0; index < grade_2.size(); index++)
		{
			if (grade_2.at(index) != "")
				size++;
		}

		Set_Grade_2_Size(size);
		break;

	case 3:
		for (int index = 0; index < grade_3.size(); index++)
		{
			if (grade_3.at(index) != "")
				size++;
		}

		Set_Grade_3_Size(size);
		break;

	case 4:
		for (int index = 0; index < grade_4.size(); index++)
		{
			if (grade_4.at(index) != "")
				size++;
		}

		Set_Grade_1_Size(size);
		break;

	case 5:
		for (int index = 0; index < grade_public.size(); index++)
		{
			if (grade_public.at(index) != "")
				size++;
		}

		Set_Grade_Public_Size(size);
		break;

	case 6:
		for (int index = 0; index < grade_all.size(); index++)
		{
			if (grade_all.at(index) != "")
				size++;
		}

		Set_Grade_All_Size(size);
		break;

	default:
		break;
	}
}

int SUBJECT::Get_Grades_Size(int grade)
{
	switch (grade)
	{
	case 1:
		return Get_Grade_1_Size();

	case 2:
		return Get_Grade_2_Size();

	case 3:
		return Get_Grade_3_Size();

	case 4:
		return Get_Grade_4_Size();

	case 5:
		return Get_Grade_Public_Size();

	case 6:
		return Get_Grade_All_Size();

	default:
		break;
	}
}

void SUBJECT::Clear_Grade_List()
{
	grade_1.clear();
	grade_2.clear();
	grade_3.clear();
	grade_4.clear();
	grade_public.clear();
	grade_all.clear();
}

void SUBJECT::Read_Lecture_List(std::string file_name)
{
	Clear_Grade_List();
	Read_File_Open(file_name);

	if (!read_file)
	{
		system("cls");
		cout << "파일 열기를 실패했습니다.";
		exit(0);
	}

	string input_lecture_information;
	while (read_file)
	{
		getline(read_file, input_lecture_information);

		switch (input_lecture_information[0])
		{
		case '1':
			grade_1.push_back(input_lecture_information);
			grade_all.push_back(input_lecture_information);
			break;

		case '2':
			grade_2.push_back(input_lecture_information);
			grade_all.push_back(input_lecture_information);
			break;

		case '3':
			grade_3.push_back(input_lecture_information);
			grade_all.push_back(input_lecture_information);
			break;

		case '4':
			grade_4.push_back(input_lecture_information);
			grade_all.push_back(input_lecture_information);
			break;

		default:
			grade_public.push_back(input_lecture_information);
			grade_all.push_back(input_lecture_information);
			break;
		}
	}
	Read_File_Close();

	Padding_Data(&grade_1);
	Padding_Data(&grade_2);
	Padding_Data(&grade_3);
	Padding_Data(&grade_4);
	Padding_Data(&grade_public);
	Padding_Data(&grade_all);
	
	Set_Grades_Size(1);
	Set_Grades_Size(2);
	Set_Grades_Size(3);
	Set_Grades_Size(4);
	Set_Grades_Size(5);
	Set_Grades_Size(6);
}

void SUBJECT::Padding_Data(std::vector<std::string>* grade)
{
	while ((grade->size() % MAX_LIST_SIZE) != 0)
		grade->push_back(" ");
}

void SUBJECT::Divide_Lecture_List(std::string origin_lecture_information, std::string array_lecture_information[])
{
	int start_index = 0;
	int find_index = 0;
	string tmp;

	for (int i = 0; i < LECTURE_DVIVISION; i++)
	{
		find_index = origin_lecture_information.find(',', start_index);
		tmp = origin_lecture_information.substr(start_index, find_index - start_index);
		start_index = find_index + 1;

		array_lecture_information[i] = tmp;
	}
}

void SUBJECT::Send_Lecture_Information(std::string sender[], std::string receiver[])
{
	receiver[0] = sender[0];
	receiver[1] = sender[1];
	receiver[2] = sender[2];
	receiver[3] = sender[3];
	receiver[4] = sender[4];
	receiver[5] = sender[5];
	receiver[6] = sender[6];
	receiver[7] = sender[7];
	receiver[8] = sender[8];
}

void SUBJECT::Send_Division_Lecture_Information(std::string file_name, int page, int grade, std::string lecture_list[][9])
{
	Read_Lecture_List(file_name);

	int vector_index = (page - 1) * MAX_LIST_SIZE;	// 읽어야할 강의 목록의 인덱스
	string array_lecture_information[9];			// 

	for (int lecture_index = 0; lecture_index < MAX_LIST_SIZE; lecture_index++)
	{
		switch (grade)
		{
		case 1:
			//if (vector_index + 1 > grade_1.size())
				//break;

			Divide_Lecture_List(grade_1.at(vector_index++), array_lecture_information);
			Send_Lecture_Information(array_lecture_information, lecture_list[lecture_index]);
			break;

		case 2:
			//if (vector_index + 1 > grade_2.size())
				//break;

			Divide_Lecture_List(grade_2.at(vector_index++), array_lecture_information);
			Send_Lecture_Information(array_lecture_information, lecture_list[lecture_index]);
			break;

		case 3:
			//if (vector_index + 1 > grade_3.size())
				//break;

			Divide_Lecture_List(grade_3.at(vector_index++), array_lecture_information);
			Send_Lecture_Information(array_lecture_information, lecture_list[lecture_index]);
			break;

		case 4:
			//if (vector_index + 1 > grade_4.size())
				//break;

			Divide_Lecture_List(grade_4.at(vector_index++), array_lecture_information);
			Send_Lecture_Information(array_lecture_information, lecture_list[lecture_index]);
			break;

		case 5:
			//if (vector_index + 1 > grade_public.size())
				//break;

			Divide_Lecture_List(grade_public.at(vector_index++), array_lecture_information);
			Send_Lecture_Information(array_lecture_information, lecture_list[lecture_index]);
			break;

		case 6:
			//if (vector_index + 1 > grade_all.size())
				//break;

			Divide_Lecture_List(grade_all.at(vector_index++), array_lecture_information);
			Send_Lecture_Information(array_lecture_information, lecture_list[lecture_index]);
			break;

		default:
			break;
		}
	}
}
