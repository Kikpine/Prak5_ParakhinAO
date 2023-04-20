/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание A
20.04.2023
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

bool arr[3002][3002];
bool flag = 1;
int Sum;
queue <pair<int, int>> Q;
set <pair<int, int>> S;

void cell_processing(int a, int b) {

	if (arr[a-1][b] == 0) {
		Q.push({a - 1,b});
		arr[a-1][b] = 1;
		Sum--;
	}
	if (arr[a][b-1] == 0) {
		Q.push({a,b-1});
		arr[a][b-1] = 1;
		Sum--;
	}
	if (arr[a+1][b] == 0) {
		Q.push({a+1,b});
		arr[a+1][b] = 1;
		Sum--;
	}
	if (arr[a][b+1] == 0) {
		Q.push({a,b+1});
		arr[a][b+1] = 1;
		Sum--;
	}

	return;
}

int main()
{
	int N, M;
	cin >> N >> M;
	Sum = N * M;

	// Заполнение стен
	for (int x = 0; x < N + 2; x++) {
		for (int y = 0; y < M + 2; y++) {
			if ((x == 0 || y == 0) || (x == N + 1 || y == M + 1)) {
				arr[x][y] = 1;
			}
		}
	}

	// Заполнение вирусами
	int quantity;
	cin >> quantity;
	for (int x = 0, y = 0, i = 0; i < quantity; i++) {
		cin >> x >> y;
		if (S.count({ x,y }) == 0) {
			S.insert({ x,y });
			Q.push({ x, y });
			arr[x][y] = 1;

			Sum--;
		}
	}

	int cnt = 0, len;

	while (Sum > 0) {
		len = Q.size();
		
		for (int i = 0; i < len; i++) {
			cell_processing(Q.front().first, Q.front().second);
			Q.pop();
		}

		cnt++;

	}

	cout << cnt << endl;
	return 0;
}