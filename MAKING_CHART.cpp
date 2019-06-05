#include "MAKING_CHART.h"


MAKING_CHART::MAKING_CHART()
{
	Set_Class_Point(0);
}


MAKING_CHART::~MAKING_CHART()
{
}

int MAKING_CHART::Add_Class_Point(string data[])
{
	Set_Class_Point(stoi(data[5]) + Get_Class_Point());

	if (Is_Full_Class_Point())
	{
		Sub_Class_Point(data);
		return 0;
	}

	return 1;
}

void MAKING_CHART::Sub_Class_Point(string data[])
{
	Set_Class_Point(Get_Class_Point() - stoi(data[5]));
}

int MAKING_CHART::Is_Full_Class_Point()
{
	if (Get_Class_Point() >= MAX_CLASS_POINT)
		return 1;

	else
		return 0;
}

void MAKING_CHART::Get_TimeTable(string time_table[][7])
{
	for (int row = 0; row < 19; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			time_table[row][col] = TimeTable[row][col];
		}
	}
}



vector<string> MAKING_CHART::tokenize_getline(const string& data, const char delimiter)
{																								//**********************************************************//
	vector<string> result;																		//														   	//
	string token = "", Dtoken = "";																//	(내부함수)												//
	stringstream ss(data);																		//	string데이터 토큰화                                     //
	int index = 0;																				//															//
	while (getline(ss, token, delimiter))														//															//
	{																							//**********************************************************//						
		result.push_back(token);
	}
	return result;
}

void MAKING_CHART::read_base_to_arr(string address)
{																	//**********************************************************//
	fin.open(address);												//															//
	if (!fin)														//	(1) address(절대주소)로 base.csv파일 읽음				//
	{																//
		//파일열기 실패 -> 종료										//															//
		exit(1);													//															//
	}																//															//
																	// (2) baes.csv 파일 읽어서 vector< vector<string> >에 저장 //
	while (getline(fin, line))										//															//
	{																//															//
		token_vector = tokenize_getline(line, ',');					//															//					
		vector_time_table.push_back(token_vector);					// (3) for문으로 벡터->배열 화								//
	}																//															//
																	//															//
	for (int i = 0; i < 19; i++)									//															//
	{																//**********************************************************//
		for (int j = 0; j < 7; j++)
		{
			TimeTable[i][j] = vector_time_table[i][j];
		}
	}
	fin.close();
}

void MAKING_CHART::arr_to_csv(string address) {
	fout.open(address); //그냥 콤마로 쓰면됨
	if (!fout) {
		//파일열기 실패 -> 종료
		exit(1);
	}
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 7; j++) {
			fout << TimeTable[i][j] << ',';
		}
		fout << endl;
	}
	fout.close();
}

int MAKING_CHART::fill_time(string* INPUT)
{
	string front = "", behind = "";
	int overlap_check_start_NUM = 0;
	int overlap_check = 1;
	int weekday = 0;
	string blank = "  ";

	if (INPUT[7].find("/") != -1) {
		// "/"를 발견하면 앞뒤로나눔
		int index = INPUT[7].find("/");
		front.assign(INPUT[7].c_str(), 0, index);
		behind.assign(INPUT[7].c_str(), index + 1, INPUT[7].length() - front.length());


		int front_start_NUM = atoi(&front[2]);
//		front_start_NUM -= 48;
		int behind_start_NUM = atoi(&behind[2]);
//		behind_start_NUM -= 48;

		switch ((int)front[0])
		{
		case -65:
			//월요일
			weekday = MONDAY;
			if (front[3] == 66) front_start_NUM *= 2;
			else front_start_NUM = front_start_NUM * 2 - 1;

			overlap_check_start_NUM = front_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][MONDAY] != "  ") {
					overlap_check = 0;
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[front_start_NUM][MONDAY] = INPUT[2];
					front_start_NUM++;
				}
			}
			break;
		case -56:
			//화요일
			weekday = TUESDAY;

			if (front[3] == 66) front_start_NUM *= 2;
			else front_start_NUM = front_start_NUM * 2 - 1;

			overlap_check_start_NUM = front_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][TUESDAY] != "  ") {
					overlap_check = 0;
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[front_start_NUM][TUESDAY] = INPUT[2];
					front_start_NUM++;
				}
			}
			break;
		case -68:
			//수요일
			weekday = WEDNESDAY;

			if (front[3] == 66) front_start_NUM *= 2;
			else front_start_NUM = front_start_NUM * 2 - 1;

			overlap_check_start_NUM = front_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][WEDNESDAY] != "  ") {
					overlap_check = 0;
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[front_start_NUM][WEDNESDAY] = INPUT[2];
					front_start_NUM++;
				}
			}
			break;
		case -72:
			//목요일
			weekday = THURSDAY;

			if (front[3] == 66) front_start_NUM *= 2;
			else front_start_NUM = front_start_NUM * 2 - 1;

			overlap_check_start_NUM = front_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][THURSDAY] != "  ") {
					overlap_check = 0;
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[front_start_NUM][THURSDAY] = INPUT[2];
					front_start_NUM++;
				}
			}
			break;
		case -79:
			//금요일
			weekday = FRIDAY;

			if (front[3] == 66) front_start_NUM *= 2;
			else front_start_NUM = front_start_NUM * 2 - 1;

			overlap_check_start_NUM = front_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][FRIDAY] != "  ") {
					overlap_check = 0;
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[front_start_NUM][FRIDAY] = INPUT[2];
					front_start_NUM++;
				}
			}
			break;
		}

		switch ((int)behind[0])
		{
		case -65:
			//월요일
			if (overlap_check == 0) break;

			if (behind[3] == 66) behind_start_NUM *= 2; // 66='B'
			else behind_start_NUM = behind_start_NUM * 2 - 1;

			overlap_check_start_NUM = behind_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][MONDAY] != "  ") {
					overlap_check = 0;
					for (int k = 0; k < 3; k++) {
						TimeTable[front_start_NUM - 1][weekday] = blank;
						front_start_NUM--;
					}
					return 1;
				}
				overlap_check_start_NUM++;
			}

			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[behind_start_NUM][MONDAY] = INPUT[2];
					behind_start_NUM++;
				}
			}

			break;
		case -56:
		{
			//화요일
			if (overlap_check == 0) break;

			if (behind[3] == 66) behind_start_NUM *= 2; // 66='B'
			else behind_start_NUM = behind_start_NUM * 2 - 1;

			overlap_check_start_NUM = behind_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][TUESDAY] != "  ") {
					overlap_check = 0;
					for (int k = 0; k < 3; k++) {
						TimeTable[front_start_NUM - 1][weekday] = blank;
						front_start_NUM--;
					}
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[behind_start_NUM][TUESDAY] = INPUT[2];
					behind_start_NUM++;
				}
			}

			break;
		}
		case -68:
		{
			//수요일
			if (overlap_check == 0) break;

			if (behind[3] == 66) behind_start_NUM *= 2; // 66='B'
			else behind_start_NUM = behind_start_NUM * 2 - 1;

			overlap_check_start_NUM = behind_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][WEDNESDAY] != "  ") {
					overlap_check = 0;
					for (int k = 0; k < 3; k++) {
						TimeTable[front_start_NUM - 1][weekday] = blank;
						front_start_NUM--;
					}
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[behind_start_NUM][WEDNESDAY] = INPUT[2];
					behind_start_NUM++;
				}
			}

			break;
		}
		case -72:
		{
			//목요일
			if (overlap_check == 0) break;

			if (behind[3] == 66) behind_start_NUM *= 2; // 66='B'
			else behind_start_NUM = behind_start_NUM * 2 - 1;

			overlap_check_start_NUM = behind_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][THURSDAY] != "  ") {
					overlap_check = 0;
					for (int k = 0; k < 3; k++) {
						TimeTable[front_start_NUM - 1][weekday] = blank;
						front_start_NUM--;
					}
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[behind_start_NUM][THURSDAY] = INPUT[2];
					behind_start_NUM++;
				}
			}

			break;
		}
		case -79:
		{
			//금요일
			if (overlap_check == 0) break;

			if ((int)behind[3] == 66) behind_start_NUM *= 2; // 66='B'
			else behind_start_NUM = behind_start_NUM * 2 - 1;

			overlap_check_start_NUM = behind_start_NUM;

			for (int i = 0; i < 3; i++) {
				if (TimeTable[overlap_check_start_NUM][FRIDAY] != "  ") {
					overlap_check = 0;
					for (int k = 0; k < 3; k++) {
						TimeTable[front_start_NUM - 1][weekday] = blank;
						front_start_NUM--;
					}
					return 1;
				}
				overlap_check_start_NUM++;
			}
			if (overlap_check) {
				for (int i = 0; i < 3; i++) {
					TimeTable[behind_start_NUM][FRIDAY] = INPUT[2];
					behind_start_NUM++;
				}
			}

			break;
		}
		}
	}

	else {
		// "/" 없으면 그냥 처리
		int index = INPUT[7].find("-");
		int index2 = INPUT[7].find("-", index + 1);

		int start = 0;
		char sss = ' ';
		sss = INPUT[7][2];
		start = atoi(&sss);
		start = start * 2 - 1;

		if (index2 == -1) { // 4칸짜리
			switch ((int)INPUT[7][0])
			{
			case -65:
				overlap_check_start_NUM = start;

				for (int i = 0; i < 4; i++) {
					if (TimeTable[overlap_check_start_NUM][MONDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 4; i++) {
						TimeTable[start][MONDAY] = INPUT[2];
						start++;
					}
				}
				break;
			case -56:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 4; i++) {
					if (TimeTable[overlap_check_start_NUM][TUESDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 4; i++) {
						TimeTable[start][TUESDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			case -68:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 4; i++) {
					if (TimeTable[overlap_check_start_NUM][WEDNESDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 4; i++) {
						TimeTable[start][WEDNESDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			case -72:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 4; i++) {
					if (TimeTable[overlap_check_start_NUM][THURSDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 4; i++) {
						TimeTable[start][THURSDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			case -79:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 4; i++) {
					if (TimeTable[overlap_check_start_NUM][FRIDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 4; i++) {
						TimeTable[start][FRIDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			}
		}
		else { // 6칸짜리
			switch ((int)INPUT[7][0])
			{
			case -65:
				overlap_check_start_NUM = start;

				for (int i = 0; i < 6; i++) {
					if (TimeTable[overlap_check_start_NUM][MONDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 6; i++) {
						TimeTable[start][MONDAY] = INPUT[2];
						start++;
					}
				}
				break;
			case -56:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 6; i++) {
					if (TimeTable[overlap_check_start_NUM][TUESDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 6; i++) {
						TimeTable[start][TUESDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			case -68:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 6; i++) {
					if (TimeTable[overlap_check_start_NUM][WEDNESDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 6; i++) {
						TimeTable[start][WEDNESDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			case -72:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 6; i++) {
					if (TimeTable[overlap_check_start_NUM][THURSDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 6; i++) {
						TimeTable[start][THURSDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			case -79:
			{
				overlap_check_start_NUM = start;

				for (int i = 0; i < 6; i++) {
					if (TimeTable[overlap_check_start_NUM][FRIDAY] != "  ") {
						overlap_check = 0;
						return 1;
					}
					overlap_check_start_NUM++;
				}
				if (overlap_check) {
					for (int i = 0; i < 6; i++) {
						TimeTable[start][FRIDAY] = INPUT[2];
						start++;
					}
				}
				break;
			}
			}
		}
	}

}
