//홈 방범 서비스
#include <iostream>
using namespace std;
int N, M;
int Map[20][20];
int DP[20][400];
int best_profit;
int Solution(int k);
void DP_process();
bool boundary(int i, int j);
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;
		best_profit = 0;
		int num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
				if (Map[i][j] == 1) {
					best_profit += M;
					num++;
				}
				DP[0][i*N + j] = Map[i][j];
			}
		}
		best_profit -= N*N + (N - 1)*(N - 1);
		if (best_profit >= 0) {
			best_profit = num;
		}
		else {
			DP_process();
			for (int i = 0; i <= N - 1; i++) {
				int result = Solution(i);
				if (result > best_profit)
					best_profit = result;
			}
		}
		cout << "#" << test_case + 1 << " " << best_profit << endl;
	}
	return 0;
}
int Solution(int k) {
	int max_num = 0;
	int operate = (k + 1)*(k + 1) + k*k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (DP[k][i*N + j] * M - operate >= 0)
				if (max_num < DP[k][i*N + j])
					max_num = DP[k][i*N + j];
		}
	}
	return max_num;
}
void DP_process() {
	for (int k = 2; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int temp = 0;
				bool i_check = true;
				bool j_check = false;
				int x = i - k + 1;
				int y = j;
				int cnt = 0;
				while (cnt < 4 * (k - 1)) {
					if (boundary(x, y))
						temp += DP[0][x*N + y];
					cnt++;
					if (i_check) x++;
					else x--;
					if (j_check) y++;
					else y--;
					if (x == i + k - 1) i_check = false;
					else if (x == i - k + 1) i_check = true;
					if (y == j - k + 1) j_check = true;
					else if (y == j + k - 1) j_check = false;
				}
				DP[k - 1][i*N + j] = DP[k - 2][i*N + j] + temp;
			}
		}
	}
}
bool boundary(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N)
		return true;
	return false;
}