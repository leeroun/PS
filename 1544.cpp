#include <iostream>
#include <vector>

using namespace std;

bool isCycleString(const string& s1, const string& s2) {
	bool chk = false;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[0] == s2[i])
		{
			for (int k = 0; k < s1.size(); k++) {
				if (s1[k] != s2[(k + i) % s1.size()])
					break;
				if (k == s1.size() - 1)
					chk = true;
			}
		}
		if (chk)
			break;
	}
	
	return chk;
}

int main() {
	int N;
	string tmp;
	vector<string> ret;
	bool cycleChk = false;

	cin >> N;
	while(N--) {
		cin >> tmp;
		if (ret.empty())
			ret.push_back(tmp);
		else {
			cycleChk = false;
			for (int j = 0; j < ret.size(); j++) {
				if (ret[j].size() == tmp.size() && isCycleString(ret[j], tmp)) {
					cycleChk = true;
					break;
				}
			}
			if (!cycleChk)
				ret.push_back(tmp);
		}
	}
	cout << ret.size()<<endl ;

	return 0;
}