//¼öÇÐ
//Silver 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t, tmp;
	vector<unsigned> vec;

	cin >> t;
	while (t--) {
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());

	cout << vec[vec.size() - 1] * vec[0] << endl;

	return 0;
}