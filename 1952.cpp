//¼ö¿µÀå
#include <iostream>
using namespace std;
int cost[4];
int sche[12];
int Result;
void DFS(int month, int sum);
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		Result = 0;
		for (int i = 0; i < 4; i++)
			cin >> cost[i];
		for (int i = 0; i < 12; i++)
			cin >> sche[i];
		Result = cost[3];
		DFS(0, 0);
		cout << "#" << test_case + 1 << " " << Result << endl;
	}
	return 0;
}
void DFS(int month, int sum) {
	if (month == 12) {
		if (Result > sum)
			Result = sum;
		return;
	}
	if (sche[month] == 0)
		DFS(month + 1, sum);
	else {
		DFS(month + 1, sum + (cost[0] * sche[month]));
		DFS(month + 1, sum + cost[1]);
		DFS(month + 3, sum + cost[2]);
	}
}