#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compareString(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= 'a')
			s1[i] -= 32;
	}
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= 'a')
			s2[i] -= 32;
	}
	if (s1.compare(s2) > 0)
		return false;
	return true;
}

int main() {
	int n;
	vector<string> vec;
	string s;

	while (true) {
		cin >> n;
		if (!n)
			break;
		vec.clear();
		for (int i = 0; i < n; i++) {
			cin >> s;
			vec.push_back(s);
		}

		sort(vec.begin(), vec.end(), compareString);

		cout << vec[0] << endl;

	}

	return 0;
}
