﻿#include <iostream>
#include <string>
#include <fstream>
#include "Mapchip.h"

int** MapchipLoading::mapchip(const char* filename, int Hrow, int Hcol, int **data) {
	
	using namespace std;
	ifstream stream(filename);
	string line;
	const int deflterow = 15;
	const int defltecol = 14;
	//MAPC McP[deflterow][defltecol];
	//APNUMBER MUP[deflterow][defltecol];
	//int data[deflterow][defltecol];
	data[Hrow][Hcol];
	const string delim = ",";

	int row = 0;
	int col;
	while (getline(stream, line)) {
		col = 0;
		// delimを区切り文字として切り分け、intに変換してdata[][]に格納する
		for (string::size_type spos, epos = 0;
			(spos = line.find_first_not_of(delim, epos)) != string::npos;) {
			string token = line.substr(spos, (epos = line.find_first_of(delim, spos)) - spos);
			data[row][col++] = stoi(token);
		}
		++row;
	}

	//                   ↓15が行数、１４が列の数
	for (row = 0; row < Hrow; ++row) {
		for (col = 0; col < Hcol; ++col) {
			cout << data[row][col] << " ";
		}
		cout << endl;
	}

	return data;
}

int MapchipLoading::textureprint(int** F, int s, int d)
{
	for (int i = 0; i < s; i++) {
		printf("\n");
		for (int j = 0; j < d; j++)
		{
			printf("%2d", F[i][j]);
		}
	}

	return 0;
}