#include <iostream>

using namespace std;

int arr[100000], dp[100000];

int main() {

	int n, max;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = max = arr[0];

	for (int i = 1; i < n; i++) {
		if (dp[i - 1] + arr[i] > arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
		if (dp[i] > max)
			max = dp[i];
	}

	cout << max;

	return 0;
}
