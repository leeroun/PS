#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main() {

	vector<pair<int, int>> v;
	int chk[101], res = 0, N;
	int a, b;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++) {
		chk[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second && chk[i] < chk[j] + 1)
				chk[i] = chk[j] + 1;
		}
		res = max(res, chk[i]);
	}

	cout << N - res << endl;

	return 0;
}
