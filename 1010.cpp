//¼öÇĞ DP
//Silver 5s
#include <iostream>

using namespace std;

int dp[31][31];

int comb(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (dp[n][r]) return dp[n][r];
	return dp[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}

int main() {

	int n, m, T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cout << comb(m, n) << endl;
	}

	return 0;
}