#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {

	int n, m;

	cin >> n;

	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		m = 1 + dp[i - (int)pow((int)sqrt(i), 2)];
		for (int j = sqrt(i) - 1; j > 1; --j) {
			m = min(m, 1 + dp[i - (int)pow(j, 2)]);
		}
		dp[i] = m;
	}

	cout << dp[n] << endl;


	return 0;
}
