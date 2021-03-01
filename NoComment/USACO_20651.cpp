#include <iostream>

using namespace std;

int main() {

	int n, arr[100], cnt = 0;
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	double ave = 0;
	for (int i = 0; i < n; ++i) {
		ave = 0;
		for (int j = i; j < n; ++j) {
			ave += arr[j];
			if (ave / (j + 1 - i) == (int)(ave / (j + 1 - i))) {
				for (int k = i; k <= j; ++k) {
					if (arr[k] == ave / (j + 1 - i)) {
						++cnt;
						break;
					}
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
