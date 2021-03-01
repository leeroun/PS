#include <iostream>

using namespace std;

int main() {

	int n;
	long long arr[10][101], cnt = 0;
	const int mod = 1000000000;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		arr[i][n - 1] = 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		arr[0][i] = (arr[1][i + 1]) % mod;
		for (int j = 1; j < 9; j++) {
			arr[j][i] = (arr[j - 1][i + 1] + arr[j + 1][i + 1]) % mod;
		}
		arr[9][i] = (arr[8][i + 1]) % mod;
	}
	for (int i = 1; i < 10; i++)
		cnt += arr[i][0];

	cout << cnt % mod;

	return 0;
}