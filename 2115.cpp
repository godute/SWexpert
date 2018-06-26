#include <iostream>
using namespace std;
int N, M ,C;
int Map[10][10];
int DynamicMap[10][10];
int temp_profit;
int Result;
void DP();
void DFS(int i, int j, int sum, int profit, int depth);
void Solution();
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M >> C;
		Result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
			}
		}
		Solution();
		cout << "#" << test_case + 1 << " " << Result << endl;
	}
	cin >> T;
	return 0;
}
void Solution() {
	DP();
	for (int i = 0; i <= N*N - (M * 2); i++) {
		if (i % N > N - M)
			continue;
		for (int j = i + M; j <= N*N - M; j++) {
			if (j % N > N - M)
				continue;
			if (Result < DynamicMap[i / N][i % N] + DynamicMap[j / N][j % N])
				Result = DynamicMap[i / N][i % N] + DynamicMap[j / N][j % N];
		}
	}
}
void DP() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			temp_profit = 0;
			DFS(i, j, 0, 0, 0);
			DynamicMap[i][j] = temp_profit;
		}
	}
}
void DFS(int i, int j, int sum, int profit, int depth) {
	if (depth >= M) {
		if (profit > temp_profit) {
			temp_profit = profit;
		}
		return;
	}
	if (sum + Map[i][j] <= C) {
		DFS(i, j + 1, sum + Map[i][j], profit + pow(Map[i][j], 2), depth + 1);
	}
	DFS(i, j + 1, sum, profit, depth + 1);
}