#include <iostream>
using namespace std;

int kruskal() {
	int no_path = 1000000;

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

	int G[7] = { 0, 1, 2, 3, 4, 5, 6 };

	for (int i = 0; i < 9; i++) {
		if (G[path[i][0]] == G[path[i][1]]) {
			continue;
		}
		else {
			int val = G[path[i][1]];
			for (int j = 0; j < 7; j++) {
				if (G[j] == val) {
					G[j] = G[path[i][0]];
				}
			}
			M[path[i][0]][path[i][1]] = path[i][2];
			M[path[i][1]][path[i][0]] = path[i][2];
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