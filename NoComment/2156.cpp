#include <iostream>
#include <algorithm>

using namespace std;

int arr[10010], dp[10010];

int main() {

	int n, res = 0;

	cin >> n;

	for (int i = 3; i < n + 3; i++)
		cin >> arr[i];

	for (int i = 3; i < n + 3; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i], dp[i-1]);
		if (i > n)
			res = max(dp[i], res);
	}
	cout << res << endl;

	return 0;
}
