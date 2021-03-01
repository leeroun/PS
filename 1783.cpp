#include <iostream>

using namespace std;

int N, M, ret = 0;

void dfs(int n, int m, int cnt) {
	if (n >= N || m >= M || n < 0 || m < 0) {
		ret = (ret > cnt - 1) ? ret : cnt - 1;
		return;
	}

	dfs(n + 2, m + 1, cnt + 1);
	dfs(n + 1, m + 2, cnt + 1);
	dfs(n - 1, m + 2, cnt + 1);
	dfs(n - 2, m + 1, cnt + 1);
}


int main() {

	cin >> N >> M;

	if (M <= 6) {
		dfs(0, 0, 1);
		if (ret >= 4)
			cout << "4" << endl;
		else
			cout << ret << endl;
	}
	else if(N == 1) {
		cout << "1" << endl;
	}
	else if (N == 2) {
		if (M > 9)
			cout << "4" << endl;
		else
			cout << (M + 1) / 2 << endl;
	}
	else {
		cout << M - 2 << endl;
	}

	return 0;
}