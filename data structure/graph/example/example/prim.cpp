#include <iostream>
#include <queue>
using namespace std;

int prim() {
	int no_path = 1000000;
	queue<int*> q;

	int path[9][3] = {
		{0, 5, 10},
		{2, 3, 12},
		{1, 6, 14},
		{1, 2, 16},
		{3, 6, 18},
		{3, 4, 22},
		{4, 6, 24},
		{4, 5, 25},
		{0, 1, 28}
	};

	int M[7][7] = {
		{no_path, no_path, no_path, no_path, no_path, no_path, no_path},
		{no_path, no_path, no_path, no_path, no_path, no_path, no_path},
		{no_path, no_path, no_path, no_path, no_path, no_path, no_path},
		{no_path, no_path, no_path, no_path, no_path, no_path, no_path},
		{no_path, no_path, no_path, no_path, no_path, no_path, no_path},
		{no_path, no_path, no_path, no_path, no_path, no_path, no_path},
		{no_path, no_path, no_path, no_path, no_path, no_path, no_path}
	};

	int G[7] = { 1, NULL, NULL, NULL, NULL, NULL, NULL };

	for (int i = 0; i < 9; i++) {
		q.push(path[i]);
	}

	while (!q.empty()) {
		bool done = false;
		int loop = q.size();
		for (int i = 0; i < loop; i++) {
			if (!done && (G[q.front()[0]] == 1) && (G[q.front()[1]] == NULL)) {
				M[q.front()[0]][q.front()[1]] = q.front()[2];
				M[q.front()[1]][q.front()[0]] = q.front()[2];
				G[q.front()[1]] = 1;
				done = true;
				q.pop();
			}
			else if (!done && (G[q.front()[0]] == NULL) && (G[q.front()[1]] == 1)) {
				M[q.front()[0]][q.front()[1]] = q.front()[2];
				M[q.front()[1]][q.front()[0]] = q.front()[2];
				G[q.front()[0]] = 1;
				done = true;
				q.pop();
			}
			else if ((G[q.front()[0]] == 1) && (G[q.front()[1]] == 1)) {
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}