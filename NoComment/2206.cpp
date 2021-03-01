#include <iostream>
#include <queue>
using namespace std;

struct node {
	int x, y;
	int cnt = 0;
	bool useCrash;
	node() {};
	node(int _x, int _y, bool uC, int cnt) : x(_x), y(_y), useCrash(uC),cnt(cnt) {};
};

int map[1001][1001];
int visit[1001][1001][2];
int n, m, nx, ny;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int bfs() {
	queue<node> q;
	q.push(node(0, 0, 0, 1));
	node tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp.x == m - 1 && tmp.y == n - 1)
			return visit[tmp.y][tmp.x][tmp.useCrash] + 1;
		for (int i = 0; i < 4; i++) {
			nx = tmp.x + dx[i];
			ny = tmp.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (!map[ny][nx] && !visit[ny][nx][tmp.useCrash]) {
				q.push(node(nx, ny, tmp.useCrash, tmp.cnt + 1));
				visit[ny][nx][tmp.useCrash] = visit[tmp.y][tmp.x][tmp.useCrash] + 1;
			}
			if (map[ny][nx] && !tmp.useCrash) {
				q.push(node(nx, ny, true, tmp.cnt + 1));
				visit[ny][nx][1] = visit[tmp.y][tmp.x][tmp.useCrash] + 1;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	cout << bfs() << endl;

	return 0;
}
