#include <iostream>

using namespace std;

int dp[1010];

int main() {

	int N, input;
	cin >> N;

	dp[1] = 1;
	for (int i = 1; i <= N; i++)
	{
		cin >> input;

		if (dp[i] == 0)
			break;

		for (int j = 1; j <= input; j++) {
			if (i + j > 1000)
				break;
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0)
				dp[i + j] = dp[i] + 1;
		}
	}
	
	cout << dp[N] - 1 << endl;

	return 0;
}