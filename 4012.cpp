//¿ä¸®»ç
#include <iostream>
using namespace std;
int T;
int N;
int S[16][16];
int arr[16];
int S_1[8];
int S_2[8];
int Result = 99999999;
void DFS(int depth, int cnt1, int cnt2);
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		Result = 99999999;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> S[j][k];
			}
			arr[j] = 0;
			S_1[j] = 0;
			S_2[j] = 0;
		}
		DFS(0, 0, 0);
		cout << "#" << i+1 << " " << Result << endl;
	}
	cin >> T;
	return 0;
}
void DFS(int depth, int cnt1, int cnt2) {
	if (depth == N) {
		int index_1 = 0;
		int index_2 = 0;
		int S1_sum = 0;
		int S2_sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] == 1) {
				S_1[index_1++] = i;
			}
			else {
				S_2[index_2++] = i;
			}
		}
		
		for (int i = 0; i < N / 2 - 1; i++) {
			for (int j = i+1; j < N / 2; j++) {
				S1_sum += S[S_1[i]][S_1[j]] + S[S_1[j]][S_1[i]];
				S2_sum += S[S_2[i]][S_2[j]] + S[S_2[j]][S_2[i]];
			}
		}
		if (abs(S1_sum - S2_sum) < Result) {
			Result = abs(S1_sum - S2_sum);
		}
		return;
	}
	if (cnt1 < N / 2) {
		arr[depth] = 1;
		DFS(depth + 1, cnt1 + 1, cnt2);
	}
	if (cnt2 < N / 2) {
		arr[depth] = 0;
		DFS(depth + 1, cnt1, cnt2 + 1);
	}
}