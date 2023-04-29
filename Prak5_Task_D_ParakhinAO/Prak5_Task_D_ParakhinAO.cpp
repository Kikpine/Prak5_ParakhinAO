/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание D
28.04.2023
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int Empty = 10000;
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
	vector <int>students(Size + 1);

	for (int i = 0; i <= Size; i++) {
		for (int j = 0; j <= Size; j++) {
			if (i == 0 || j == 0) {
				L1[i][j] = Empty;
				L2[i][j] = Empty;
			}
			else {
				cin >> L1[i][j];
				if (L1[i][j] == 0) {
					L1[i][j] = Empty;
				}
				L2[i][j] = L1[i][j];
			}
		}
	}

	Floid(L1, L2, temp);

	int col_student = 0;
	for (int i = 1; i <= Size; i++) {
		cin >> col_student;
		students[i] = col_student;
	}

	int Min = 9999999, tmp, village = 0;
	for (int i = 1; i <= Size; i++) {
		tmp = 0;
		for (int j = 1; j <= Size; j++) {
			if (j != i) {
				tmp += students[j] * L2[j][i];
			}
		}
		if (tmp < Min) {
			Min = tmp;
			village = i;
		}
	}

	cout << village << ' ' << Min << endl;
	return 0;
}