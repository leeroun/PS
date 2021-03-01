//±¸Çö
//Silver 5
#include <iostream>

using namespace std;

int main() {

	int map[101][101] = { 0, };
	int n, m, x1, x2, y1, y2;
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y <= y2; y++)
			for (int x = x1; x <= x2; x++)
				map[y][x]++;
	}

	for (int y = 1; y <= 100; y++)
		for (int x = 1; x <= 100; x++)
			if (map[y][x] > m) {
				cnt++;
			}
	cout << cnt;
	return 0;
}
