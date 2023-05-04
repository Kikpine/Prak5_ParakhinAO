/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание C
26.04.2023
*/

#include <iostream>
#include <vector>
using namespace std;
int Size;

int main()
{
	cin >> Size;
	vector <vector <int>>L1(Size + 1, vector <int>(Size + 1, 0));

	int Road_col;
	cin >> Road_col;
	for (int k = 0; k < Road_col; k++) {
		int i, j, l;
		cin >> i >> j >> l;
		L1[i][j] = L1[j][i] = l;
	}
	for (int i = 0; i <= Size; i++) {
		for (int j = 0; j <= Size; j++) {
			if (i == 0 || j == 0) {
				L1[i][j] = 0;
			}
		}
	}

	//for (int i = 1; i <= Size; i++) {
	//	for (int j = 1; j <= Size; j++) {
	//		cout << L1[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	int no_edge;  

	vector <bool> selected(Size+1);

	no_edge = 0;

	selected[1] = true;

	int x;
	int y;

	long long int result = 0;

	while (no_edge < Size) {

		long long int min = 999999999999;
		x = 0;
		y = 0;

		for (int i = 0; i <= Size; i++) {
			if (selected[i]) {
				for (int j = 0; j <= Size; j++) {
					if (!selected[j] && L1[i][j]) {
						if (min > L1[i][j]) {
							min = L1[i][j];
							x = i;
							y = j;
						}

					}
				}
			}
		}
		result += L1[x][y];
		selected[y] = true;
		no_edge++;
	}

	cout << result << endl;
	return 0; 
}