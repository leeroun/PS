//수학 브루트 포스
//Silver 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n, start = 0, end = 0, L, tmp;
	vector<int> vec;
	cin >> L;
	while (L--) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	cin >> n;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == n) {
			cout << "0" << endl;
			return 0;
		}
		else if (vec[i] > n) {
			if (i == 0)
				start = 1;
			else
				start = vec[i - 1] + 1;
			end = vec[i] - 1;
			break;
		}
		
	}
	cout << (n - start) * (end - n + 1) + (end - n) << endl;

	return 0;
}