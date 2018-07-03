//미생물 격리
#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
int Map[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
struct cluster {
	int x;
	int y;
	int size;
	int dire;
};
vector<cluster> vec;
vector<cluster> temp;	//합치는거 고려하려공
void Solution();
int Calc();
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			cluster node;
			cin >> node.x >> node.y >> node.size >> node.dire;
			vec.push_back(node);
		}
		Solution();
		cout << "#" << test_case + 1 << " " << Calc() << endl;
		vec.clear();
	}
	return 0;
}
void Solution() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < vec.size(); j++) {
			vec[j].x += dx[vec[j].dire - 1];
			vec[j].y += dy[vec[j].dire - 1];
			if (vec[j].x == 0 || vec[j].x == N - 1 || vec[j].y == 0 || vec[j].y == N - 1) {
				vec[j].size /= 2;
				if (vec[j].dire == 1) vec[j].dire = 2;
				else if (vec[j].dire == 2) vec[j].dire = 1;
				else if (vec[j].dire == 3) vec[j].dire = 4;
				else vec[j].dire = 3;
				if (vec[j].size == 0) {
					vec.erase(vec.begin() + j);
					j--;
				}
			}
		}
		for (int j = 0; j < vec.size(); j++) {
			int temp_size = vec[j].size;
			int big_size = temp_size;
			int dir = vec[j].dire;
			for (int k = j + 1; k < vec.size(); k++) {
				if (vec[j].x == vec[k].x && vec[j].y == vec[k].y) {
					temp_size += vec[k].size;
					if (vec[k].size > big_size) {
						big_size = vec[k].size;
						dir = vec[k].dire;
					}
					vec.erase(vec.begin() + k);
					//vec.resize(vec.size() - 1);
					k--;
				}
			}
			cluster new_node;
			new_node.size = temp_size;
			new_node.x = vec[j].x;
			new_node.y = vec[j].y;
			new_node.dire = dir;
			temp.push_back(new_node);
		}
		vec.clear();
		for (int i = 0; i < temp.size(); i++)
			vec.push_back(temp[i]);
		temp.clear();
	}
}
int Calc() {
	int result = 0;
	for (int i = 0; i < vec.size(); i++) result += vec[i].size;
	return result;
}