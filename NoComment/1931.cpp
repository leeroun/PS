#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool cmp(pair<int, int> f, pair<int, int> s) {
	if (f.second == s.second)
		return f.first < s.first;
	else
		return f.second < s.second;
}

int main() {

	vector<pair<int, int>> p;
	int n, s, e, i;

	cin >> n;

	for ( i = 0; i < n; i++) {
		cin >> s >> e;
		p.push_back(make_pair(s, e));
	}

	sort(p.begin(), p.end(), cmp);

	int cur = p[0].second, cnt = 1;
	for (i = 1; i < n; i++) {
		if (cur <= p[i].first)
		{
			cnt++;
			cur = p[i].second;
		}
	}

	cout << cnt;

	return 0;
}
