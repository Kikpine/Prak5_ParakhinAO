/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание A
18.04.2023
*/

#include <iostream>
#include <cmath>
using namespace std;

bool arr[3002][3002];

void Make_Cell_Value(int a, int b) {

	return;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int x = 0; x < N + 2; x++) {
		for (int y = 0; y < M + 2; y++) {
			if ((x == 0 || y == 0) || (x == N + 1 || y == M + 1)) {
				arr[x][y] = 1;
				arr[x][y] = 1;
			}
		}
	}

	// Заполнение вирусами
	int quantity;
	cin >> quantity;
	for (int x = 0, y = 0, i = 0; i < quantity; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
	}



	return 0;
}