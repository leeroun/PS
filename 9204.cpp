#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

bool firstChk[8][8], secondChk[8][8];

void chkCross(bool isFirst, int x, int y) {
	int c_x = x, c_y = y;
	while (c_x >= 0 && c_y >= 0) {
		if(isFirst)
			firstChk[c_y][c_x] = true;
		else
			secondChk[c_y][c_x] = true;
		--c_x;
		--c_y;
	}
	c_x = x;
	c_y = y;
	while (c_x < 8 && c_y >= 0) {
		if (isFirst)
			firstChk[c_y][c_x] = true;
		else
			secondChk[c_y][c_x] = true;
		++c_x;
		--c_y;
	}
	c_x = x;
	c_y = y;
	while (c_x < 8 && c_y < 8) {
		if (isFirst)
			firstChk[c_y][c_x] = true;
		else
			secondChk[c_y][c_x] = true;
		++c_x;
		++c_y;
	}
	c_x = x;
	c_y = y;
	while (c_x >= 0 && c_y < 8) {
		if (isFirst)
			firstChk[c_y][c_x] = true;
		else
			secondChk[c_y][c_x] = true;
		--c_x;
		++c_y;
	}
}

int main() {
	int T, x1, y1, x2, y2;
	char x_c1, x_c2;
	vector<pair<int, int>> v;

	cin >> T;

	while (T--) {
		v.clear();
		cin >> x_c1 >> y1 >> x_c2 >> y2;
		x1 = x_c1 - 'A';
		x2 = x_c2 - 'A';

		if (x1 == x2 && y1 == y2) {
			cout << "0 " << x_c1 << " " << y1 << endl;
			continue;
		}
		else if ((abs(x1 - x2) + abs(y1 - y2)) % 2) {
			cout << "Impossible" << endl;
			continue;
		}
		chkCross(true, x1, y1 - 1);
		chkCross(false, x2, y2 - 1);
			
		for(int i =0; i<8; i++)
			for (int j = 0; j < 8; j++) {
				if (firstChk[i][j] && secondChk[i][j])
					v.push_back(make_pair(i, j));
			}
		if (v.size() > 2)
			cout << "1 " << x_c1 << " " << y1 << " " << x_c2 << " " << y2 << endl;
		else
			cout << "2 " << x_c1 << " " << y1 << " " << (char)(v[0].second + 'A') << " " << v[0].first + 1 << " " << x_c2 << " " << y2 << endl;
	}

	return 0;
}