//숫자 만들기.
#include <iostream>
using namespace std;
int N;
int Numbers[12];
int Opers[4];
int Max_res, Min_res;
void DFS(int plus, int minus, int multi, int divide, int operand, int depth);
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		Min_res = 100000000;
		Max_res = -100000000;
		for (int i = 0; i < 4; i++)
			cin >> Opers[i];
		for (int i = 0; i < N; i++)
			cin >> Numbers[i];
		DFS(Opers[0], Opers[1], Opers[2], Opers[3], Numbers[0], 1);
		cout << "#" << test_case + 1 << " " << Max_res - Min_res << endl;
	}
	return 0;
}
void DFS(int plus, int minus, int multi, int divide, int operand, int depth) {
	if (depth == N) {
		if (operand > Max_res)
			Max_res = operand;
		if (operand < Min_res)
			Min_res = operand;
		return;
	}
	if (plus != 0) DFS(plus - 1, minus, multi, divide, operand + Numbers[depth], depth + 1);
	if (minus != 0) DFS(plus, minus - 1, multi, divide, operand - Numbers[depth], depth + 1);
	if (multi != 0) DFS(plus, minus, multi - 1, divide, operand*Numbers[depth], depth + 1);
	if (divide != 0) DFS(plus, minus, multi, divide - 1, operand / Numbers[depth], depth + 1);
}