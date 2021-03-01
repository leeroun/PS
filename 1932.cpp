#include <iostream>

using namespace std;

int arr[500][500];

int main() {

	int n, max = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i < n; i++) {
		arr[i][0] += arr[i - 1][0];
		arr[i][i] += arr[i - 1][i - 1];
		for (int j = 1; j < i; j++)
		{
			arr[i][j] += (arr[i - 1][j - 1] > arr[i - 1][j]) ? arr[i - 1][j - 1] : arr[i - 1][j];
		}
	}

	for (int i = 0; i < n; i++) {
		max = (arr[n - 1][i] > max) ? arr[n - 1][i] : max;
	}
	cout << max;
	return 0;
}