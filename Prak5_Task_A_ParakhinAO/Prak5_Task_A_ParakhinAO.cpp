/*
МОП ЭВМ ИКТИБ ЮФУ
Структуры и алгоритмы обработки данных
Парахин А.О. КТбо1-7
Практика 5 Задание A
18.04.2023
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

bool arr[3002][3002];
bool flag = 1;

vector <pair<int, int>> marked;

void cell_processing(int a, int b) {

	if (arr[a][b] == 1) {
		if (arr[a-1][b] == 0 && std::find(marked.begin() + 1, marked.end(), make_pair(a - 1, b)) == marked.end()) {
			marked.push_back({a - 1,b});
		}
		if (arr[a][b-1] == 0 && std::find(marked.begin() + 1, marked.end(), make_pair(a, b - 1)) == marked.end()) {
			marked.push_back({a,b-1});
		}
		if (arr[a+1][b] == 0 && std::find(marked.begin() + 1, marked.end(), make_pair(a+1, b)) == marked.end()) {
			marked.push_back({a+1,b});
		}
		if (arr[a][b+1] == 0 && std::find(marked.begin() + 1, marked.end(), make_pair(a, b+1)) == marked.end()) {
			marked.push_back({a,b+1});
		}
	}

	return;
}

void pop_all_set() {

	for (auto it = marked.begin(); it != marked.end(); it++) {
		arr[(*it).first][(*it).second] = 1;
		flag = 1;
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
		marked.push_back({ x, y });
	}

	int cnt = -1, len;
	while (flag == 1) {
		len = marked.size();
		for (int i = 0; i < len; i++) {
			int x = marked[0].first, y = marked[0].second;
			
			cell_processing(x, y);
			marked.erase(marked.begin());
		}

		flag = 0;
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= M; y++) {
				cout << arr[x][y] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		pop_all_set();
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}