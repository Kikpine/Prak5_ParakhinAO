/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание B
26.04.2023
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int Empty = 9999;
int Size;

void Floid(vector <vector <int>>&L1, vector <vector <int>>&L2, vector <vector <int>>&temp, vector <vector <int>>&answers) {

	for (int k = 1; k <= Size; k++) {
		for (int i = 1; i <= Size; i++) {
			for (int j = 1; j <= Size; j++) {
				L1[i][j] = min(L1[i][j], L1[i][k] + L1[k][j]);
				if (L1[i][j] == L1[i][k] + L1[k][j]) {
					answers[i][j] = k;
				}
			}
		}
	}

	temp = L1;
	L1 = L2;
	L2 = temp;

	return;
}

void path(int i, int j, vector <vector <int>>& L2) {
	int k;
	k = L2[i][j];
	if (k == 0) {
		return;
	}
	path(i, k, L2);
	cout << k << ' ';
	path(k, j, L2);
}

int main()
{
	cin >> Size;

	vector <vector <int>>L1(Size+1, vector <int> (Size+1));
	vector <vector <int>>L2(Size+1, vector <int> (Size+1));
	vector <vector <int>>temp(Size+1, vector <int> (Size+1));
	vector <vector <int>>answers(Size+1, vector <int> (Size+1));

	for (int i = 0; i <= Size; i++) {
		for (int j = 0; j <= Size; j++) {
			if (i == 0 || j == 0) {
				L1[i][j] = Empty;
				L2[i][j] = Empty;
			}
			else {
				cin >> L1[i][j];
				L2[i][j] = L1[i][j];
				if (L1[i][j] == 0) {
					L1[i][j] = L2[i][j] = Empty;
				}
			}
		}
	}

	int Start, End;
	cin >> Start >> End;

	Floid(L1, L2, temp, answers);
	if (L2[Start][End] == Empty) {
		cout << 0 << endl;
	}
	else {
		cout << L2[Start][End] << endl;

		cout << Start << ' ';
		path(Start, End, answers);
		cout << End << endl;
	}
	return 0;
}