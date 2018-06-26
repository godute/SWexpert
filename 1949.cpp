//등산로조성
#include <iostream>

using namespace std;

int N;
int K;
int Mountain[8][8];
int Visited[8][8];
int highest;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void DFS(int i, int j, int cnt, bool K_use);
bool boundary(int i, int j);
int length;

int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> K;
		highest = 0;
		length = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Mountain[i][j];
				Visited[i][j] = 0;
				if (highest < Mountain[i][j])
					highest = Mountain[i][j];
			}
		}	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Mountain[i][j] == highest) {
					DFS(i, j, 1, true);
				}
			}
		}
		cout << "#" << test_case +1 << " " <<length << endl;
	}
	cin >> T;
	return 0;
}
void DFS(int i, int j, int cnt, bool K_use) {
	Visited[i][j] = 1;
	for (int x = 0; x < 4; x++) {
		if (boundary(i + dx[x], j + dy[x])) {
			if (Mountain[i][j] > Mountain[i + dx[x]][j + dy[x]]) {
				DFS(i + dx[x], j + dy[x], cnt + 1, K_use);
			}
			else if (Mountain[i][j] <= Mountain[i + dx[x]][j + dy[x]] && K_use) {
				if (K > Mountain[i + dx[x]][j + dy[x]] - Mountain[i][j]) {
					K_use = false;
					int temp = Mountain[i + dx[x]][j + dy[x]];
					Mountain[i + dx[x]][j + dy[x]] = Mountain[i][j] - 1;
					DFS(i + dx[x], j + dy[x], cnt + 1, K_use);
					Mountain[i + dx[x]][j + dy[x]] = temp;
					K_use = true;
				}
			}
		}
	}
	Visited[i][j] = 0;
	if (length < cnt) {
		length = cnt;
	}
}
bool boundary(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < N && Visited[i][j] == 0) {
		return true;
	}
	return false;
}