/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание A
18.04.2023
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef int value;
int Max = 0;

value Make_Cell_Value(int a, int b, vector<vector<value>>&V) {
	if (V[a][b] == 0) {
		return 0;
	}

	int result = 1 + min(min(V[a-1][b], V[a+1][b]),min(V[a][b-1], V[a][b+1]));

	return result;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<value>>V(N + 2, vector<value>(M + 2, 8888));
	
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			V[x][y] = 9999;
		}
	}

	// Заполнение вирусами
	int quantity;
	cin >> quantity;
	for (int x = 0, y = 0, i = 0; i < quantity; i++) {
		cin >> x >> y;
		V[x][y] = 0;
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			V[x][y] = Make_Cell_Value(x, y, V);
		}
	}

	for (int x = N; x > 0; x--) {
		for (int y = M; y > 0; y--) {
			V[x][y] = Make_Cell_Value(x, y, V);
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			if (V[x][y] > Max) {
				Max = V[x][y];
			}
		}
	}
	
	//// Проверка выводом
	//for (int x = 0; x < N+2; x++) {
	//	for (int y = 0; y < M+2; y++) {
	//		cout << ' ' << V[x][y];
	//	}
	//	cout << endl;
	//}

	cout << Max << endl;

	return 0;
}