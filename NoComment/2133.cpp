#include <iostream>

using namespace std;

int main() {

	int n, arr[31] = { 0, };

	cin >> n;

	arr[0] = 1;
	arr[2] = 3;

	for (int i = 4; i <= n; i+=2) {
		arr[i] = arr[i - 2] * arr[2];
		for (int j = 4; j <= i; j += 2)
			arr[i] += arr[i - j] * 2;
	}

	cout << arr[n];

	return 0;
}
