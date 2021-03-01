#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int max = 0, input[7];
	vector<int> v;

	for (int i = 0; i < 7; ++i) {
		cin >> input[i];
		max = (input[i] > max) ? input[i] : max;
	}

	for (int _a = 0; _a < 7; ++_a) {
		for (int _b = 0; _b < 7; ++_b) {
			for (int _c = 0; _c < 7; ++_c) {
				if (input[_a] + input[_b] + input[_c] == max) {
					v.push_back(input[_a]);
					v.push_back(input[_b]);
					v.push_back(input[_c]);
				}
			}
			if (!v.empty())
				break;
		}
		if (!v.empty())
			break;
	}

	sort(v.begin(), v.end());

	for (auto& a : v) {
		cout << a << " ";
	}

	return 0;
}
