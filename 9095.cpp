#include <iostream>

using namespace std;

int main() {

	int n, T;
	cin >> T;
	while (T--) {
		int dp[12] = { 0, };
		dp[0] = 1;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			for(int j =1; j<=3; j++){
				if (i - j >= 0) dp[i] += dp[i - j];
			}
		}
		cout << dp[n] << endl;
	}

	return 0;
}