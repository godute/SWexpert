//Å»ÁÖ¹ü °Ë°Å
#include <iostream>
#include <queue>

using namespace std;
int N, M, R, C, L;
int Map[50][50];
int Visited[50][50];
int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };
struct node {
	pair<int, int> location;
	int time;
};
queue<node> q;
int BFS();
bool boundary(int i, int j);
bool promissing(int i, int j, int k);
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> Map[i][j];
				Visited[i][j] = 0;
			}
		}
		Visited[R][C] = 1;
		node first_node;
		first_node.location = make_pair(R, C);
		first_node.time = 0;
		q.push(first_node);
		cout << "#" << test_case + 1 << " " << BFS() << endl;
	}
	return 0;
}
int BFS() {
	int result = 0;
	while (!q.empty()) {
		node n = q.front();
		int i = n.location.first;
		int j = n.location.second;
		int t = n.time;
		q.pop();
		if (t == L-1)
			continue;
		for (int k = 0; k < 4; k++) {
			node new_node;
			bool check = false;
			if (boundary(i + dx[k], j + dy[k])) {
				if (Visited[i + dx[k]][j + dy[k]] == 0) {
					switch (Map[i][j]) {
					case 1: {
						if (promissing(i + dx[k], j + dy[k], k)) check = true;
						break;
					}
					case 2: {
						if (k == 0 || k == 1) 
							if (promissing(i + dx[k], j + dy[k], k)) check = true;
						break;
					}
					case 3: {
						if (k == 2 || k == 3)
							if (promissing(i + dx[k], j + dy[k], k)) check = true;
						break;
					}
					case 4: {
						if (k == 1 || k == 2) 	
							if (promissing(i + dx[k], j + dy[k], k)) check = true;
						break;
					}
					case 5: {
						if (k == 0 || k == 2) 
							if (promissing(i + dx[k], j + dy[k], k)) check = true;
						break;
					}
					case 6: {
						if (k == 0 || k == 3) 	
							if (promissing(i + dx[k], j + dy[k], k)) check = true;
						break;
					}
					case 7: {
						if (k == 1 || k == 3) 	
							if (promissing(i + dx[k], j + dy[k], k)) check = true;
						break;
					}
					}
				}
			}
			if (check) {
				new_node.location = make_pair(i + dx[k], j + dy[k]);
				new_node.time = t + 1;
				Visited[i + dx[k]][j + dy[k]] = 1;
				q.push(new_node);
			}
		}
	}
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (Visited[x][y] == 1)
				result++;
		}
	}
	return result;
}
bool boundary(int i, int j) {
	if (i >= 0 && i < N && j >= 0 && j < M)
		return true;
	return false;
}
bool promissing(int i, int j, int k) {
	switch (k) {
	case 0: {
		if (Map[i][j] == 1 || Map[i][j] == 2 || Map[i][j] == 4 || Map[i][j] == 7) return true;
		break;
	}
	case 1: {
		if (Map[i][j] == 1 || Map[i][j] == 2 || Map[i][j] == 5 || Map[i][j] == 6) return true;
		break;
	}
	case 2: {
		if (Map[i][j] == 1 || Map[i][j] == 3 || Map[i][j] == 6 || Map[i][j] == 7) return true;
		break;
	}
	case 3: {
		if (Map[i][j] == 1 || Map[i][j] == 3 || Map[i][j] == 4 || Map[i][j] == 5) return true;
		break;
	}
	}
	return false;
}