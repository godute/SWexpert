//특이한 자석
#include <iostream>
#include <cmath>
using namespace std;
int K;
int Magnet[4][8];
int temp_mag[4][8];
int K_list[20][2];
bool check_list[4];
int direction[4];
int Solution();
void switch_magnet(int num, int k);
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> K;
		for (int i = 0; i < 4; i++) for (int j = 0; j < 8; j++) cin >> Magnet[i][j];
		for (int i = 0; i < K; i++)
			cin >> K_list[i][0] >> K_list[i][1];
		cout << "#" << test_case + 1 << " " << Solution() << endl;
	}
	return 0;
}
int Solution() {
	int Result = 0;
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < 4; i++)
			check_list[i] = false;
		switch (K_list[k][0]) {
		case 1: {
			check_list[0] = true;
			if (Magnet[0][2] != Magnet[1][6]) {
				check_list[1] = true;
				if (Magnet[1][2] != Magnet[2][6]) {
					check_list[2] = true;
					if (Magnet[2][2] != Magnet[3][6]) {
						check_list[3] = true;
					}
				}
			}
			break;
		}
		case 2: {
			check_list[1] = true;
			if (Magnet[0][2] != Magnet[1][6]) {
				check_list[0] = true;
			}
			if (Magnet[1][2] != Magnet[2][6]) {
				check_list[2] = true;
				if (Magnet[2][2] != Magnet[3][6]) {
					check_list[3] = true;
				}
			}
			break;
		}
		case 3: {
			check_list[2] = true;
			if (Magnet[1][2] != Magnet[2][6]) {
				check_list[1] = true;
				if (Magnet[0][2] != Magnet[1][6]) {
					check_list[0] = true;
				}
			}
			if (Magnet[2][2] != Magnet[3][6]) {
				check_list[3] = true;
			}
			break;
		}
		case 4: {
			check_list[3] = true;
			if (Magnet[2][2] != Magnet[3][6]) {
				check_list[2] = true;
				if (Magnet[1][2] != Magnet[2][6]) {
					check_list[1] = true;
					if (Magnet[0][2] != Magnet[1][6]) {
						check_list[0] = true;
					}
				}
			}
			break;
		}
		}
		for (int i = 0; i < 4; i++) {
			if (check_list[i]) {
				if (K_list[k][0] % 2 != 0) {
					if (i % 2 == 0)
						direction[i] = K_list[k][1];
					else
						direction[i] = -K_list[k][1];
				}
				else {
					if (i % 2 == 0)
						direction[i] = -K_list[k][1];
					else
						direction[i] = K_list[k][1];
				}
				switch_magnet(i, direction[i]);
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (Magnet[i][0] == 1)
			Result += pow(2, i);
	}
	return Result;
}
void switch_magnet(int num, int k) {
	for (int i = 0; i < 8; i++)
		temp_mag[num][i] = Magnet[num][i];
	switch (k) {
	case 1: {
		for (int i = 0; i < 8; i++) {
			if (i == 0)
				Magnet[num][i] = temp_mag[num][7];
			else
				Magnet[num][i] = temp_mag[num][i - 1];
		}
		break;
	}
	case -1: {
		for (int i = 0; i < 8; i++) {
			if (i == 7)
				Magnet[num][i] = temp_mag[num][0];
			else
				Magnet[num][i] = temp_mag[num][i + 1];
		}
		break;
	}
	}
}