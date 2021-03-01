#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> v;
	int n, m, input, a, b, _min, _max;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	while (m--) {
		cin >> a >> b;
		_min = 1000000000;
		_max = 0;
		for (int i = a - 1; i <= b - 1; i++) {
			_min = (_min < v[i]) ? _min : v[i];
			_max = (_max > v[i]) ? _max : v[i];
		}
		cout << _min << " " << _max << endl;
	}

	return 0;
}
