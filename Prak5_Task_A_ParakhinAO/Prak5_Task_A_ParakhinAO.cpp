/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание A
18.04.2023
*/

#include <iostream>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

bool arr[3002][3002];
bool flag = 1;
queue <pair<int,int>> Q;
set <pair<int, int>> marked;

void cell_processing(int a, int b) {

	if (arr[a][b] == 1) {
		if (arr[a-1][b] == 0) {
			Q.push({a - 1,b});
			marked.insert({ a,b });
		}
		if (arr[a][b-1] == 0) {
			Q.push({a,b-1});
			marked.insert({ a,b });
		}
		if (arr[a+1][b] == 0) {
			Q.push({a+1,b});
			marked.insert({ a,b });
		}
		if (arr[a][b+1] == 0) {
			Q.push({a,b+1});
			marked.insert({ a,b });
		}
	}

	return;
}

void pop_all_queue() {

	while (!Q.empty()){
		arr[Q.front().first][Q.front().second] = 1;
		flag = 1;
		
		Q.pop();
	}

	return;
}

int main()
{
	int N, M;
	cin >> N >> M;

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
		arr[x][y] = 1;
	}

	int cnt = -1;
	pair<int, int>temp;
	while (flag == 1) {

		for (int x = 1; x <= N ; x++) {
			for (int y = 1; y <= M; y++) {
				temp.first = x;
				temp.second = y;
				if (!marked.count(temp)) {
					cell_processing(x, y);
				}
			}
		}

	int cnt = -1;
	while (flag == 1) {

		for (int x = 1; x <= N ; x++) {
			for (int y = 1; y <= M; y++) {
				if (!marked.count({x,y})) {
					cell_processing(x, y);
				}
			}
		}

		flag = 0;
		pop_all_queue();
		cnt++;
		cout << endl << endl;

	}


	//for (int x = 1; x <= N; x++) {
	//	for (int y = 1; y <= M; y++) {
	//		cout << arr[x][y] << ' ';
	//	}
	//	cout << endl;
	//}


	cout << cnt << endl;
	return 0;
}