#include <iostream>
#include <stack>

using namespace std;

int map[9][9], i, j;
bool rowChk[9][10];
bool colChk[9][10];
bool squareChk[9][10];

void dfs(int x, int y) {
	if (x == 9) {
		++y;
		x = 0;
	}
	if (y > 8) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	if (map[y][x] == 0) {
		for (int i = 1; i < 10; i++) {
			if (!rowChk[y][i] && !colChk[x][i] && !squareChk[(y / 3) * 3 + x / 3][i]) {
				map[y][x] = i;
				rowChk[y][i] = true;
				colChk[x][i] = true;
				squareChk[(y / 3) * 3 + x / 3][i] = true;
				dfs(x + 1, y);
				map[y][x] = 0;
				rowChk[y][i] = false;
				colChk[x][i] = false;
				squareChk[(y / 3) * 3 + x / 3][i] = false;
			}
		}
	}
	else
		dfs(x + 1, y);
}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				rowChk[i][map[i][j]] = true;
				colChk[j][map[i][j]] = true;
				squareChk[(i / 3) * 3 + j / 3][map[i][j]] = true;
			}
		}
	}

	dfs(0, 0);


	return 0;
}