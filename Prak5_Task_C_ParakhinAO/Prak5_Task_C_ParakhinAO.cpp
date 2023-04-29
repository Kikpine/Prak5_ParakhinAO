/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание C
26.04.2023
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int Empty = 9999;
int Size;

void Floid(vector <vector <int>>& L1, vector <vector <int>>& L2, vector <vector <int>>& temp) {

	for (int k = 1; k <= Size; k++) {
		L1[k][k] = 0;
		for (int i = 1; i <= Size; i++) {
			for (int j = 1; j <= Size; j++) {
				L1[i][j] = min(L1[i][j], L1[i][k] + L1[k][j]);
			}
		}
	}

	temp = L1;
	L1 = L2;
	L2 = temp;

	return;
}

int main()
{
	cin >> Size;
	vector <vector <int>>L1(Size + 1, vector <int>(Size + 1, Empty));
	vector <vector <int>>L2(Size + 1, vector <int>(Size + 1, Empty));
	vector <vector <int>>temp(Size + 1, vector <int>(Size + 1, Empty));

	int Road_col;
	cin >> Road_col;
	for (int k = 0; k < Road_col; k++) {
		int i, j, l;
		cin >> i >> j >> l;
		L1[i][j] = L1[j][i] = l;
		L2[i][j] = L2[j][i] = l;
	}
	for (int i = 0; i <= Size; i++) {
		for (int j = 0; j <= Size; j++) {
			if (i == 0 || j == 0) {
				L1[i][j] = Empty;
				L2[i][j] = Empty;
			}
			else {
				if (L1[i][j] == 0) {
					L1[i][j] = L2[i][j] = Empty;
				}
			}
		}
	}

	Floid(L1, L2, temp);
	
	int Max = 0;
	for (int i = 1; i <= Size; i++) {
		for (int j = 1; j <= Size; j++) {
			if (L2[i][j] > Max && L2[i][j] < Empty) {
				Max = L2[i][j];
			}
		}
	}

	cout << Max << endl;
	return 0;
}