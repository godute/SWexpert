//활주로 건설
#include <iostream>
using namespace std;
int N, X;
int Map[20][20];
int Visited_i[20][20];  //수직 확인
int Visited_j[20][20];  //수평 확인
int Solution();
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
				Visited_i[i][j] = 0;
				Visited_j[i][j] = 0;
			}
		}
		cout << "#" << test_case + 1 << " " << Solution() << endl;
	}
	return 0;
}
int Solution() {
	int Result = 0;
	for (int i = 0; i < N; i++) {
		int index = 0;
		bool check = true;
		while (index < N - 1 && check) {

			bool temp_check = true;
			if (Map[i][index] == Map[i][index + 1] + 1) {
				if (index + X >= N) {
					check = false;
					break;
				}
				for (int j = 0; j < X; j++) {
					if (Map[i][index + 1] == Map[i][index + 1 + j]) {
						if (Visited_i[i][index + 1 + j] == 1) {
							check = false;
							break;
						}
						Visited_i[i][index + 1 + j] = 1;
					}
					else {
						check = false;
						break;
					}
				}
				index += X;
			}
			else if (Map[i][index] == Map[i][index + 1] - 1) {
				if (index + 1 - X < 0) {
					check = false;
					break;
				}
				for (int j = 0; j < X; j++) {
					if (Map[i][index] == Map[i][index - j]) {
						if (Visited_i[i][index - j] == 1) {
							check = false;
							break;
						}

						Visited_i[i][index - j] = 1;
					}
					else {
						check = false;
						break;
					}
				}
				index++;
			}
			else if (Map[i][index] == Map[i][index + 1]) {
				index++;
			}
			else {
				check = false;
				break;
			}
		}
		if (check) Result++;
		check = true;
		index = 0;
		while (index < N - 1 && check) {
			bool temp_check = true;
			if (Map[index][i] == Map[index + 1][i] + 1) {
				if (index + X >= N) {
					check = false;
					break;
				}
				for (int j = 0; j < X; j++) {
					if (Map[index + 1][i] == Map[index + 1 + j][i]) {
						if (Visited_j[index + 1 + j][i] == 1) {
							check = false;
							break;
						}
						Visited_j[index + 1 + j][i] = 1;
					}
					else {
						check = false;
						break;
					}
				}
				index += X;
			}
			else if (Map[index][i] == Map[index + 1][i] - 1) {
				if (index + 1 - X < 0) {
					check = false;
					break;
				}
				for (int j = 0; j < X; j++) {
					if (Map[index][i] == Map[index - j][i]) {
						if (Visited_j[index - j][i] == 1) {
							check = false;
							break;
						}
						Visited_j[index - j][i] = 1;
					}
					else {
						check = false;
						break;
					}
				}
				index++;
			}
			else if (Map[index][i] == Map[index + 1][i]) {
				index++;
			}
			else {
				check = false;
				break;
			}
		}
		if (check) Result++;
	}
	return Result;
}