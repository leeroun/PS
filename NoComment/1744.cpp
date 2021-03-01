#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bigger(const int& x, const int& y) {
	return x > y;
}

int main() {

	int result = 0, n, input, tmp = 0;
	vector<int> vecP, vecM;
	bool isZero = false;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0)
			isZero = true;
		else if(input > 0)
			vecP.push_back(input);
		else
			vecM.push_back(input);
	}

	sort(vecP.begin(), vecP.end(), bigger);
	sort(vecM.begin(), vecM.end());

	for (int i = 0; i < vecP.size(); i++) {
		if (vecP[i] == 1)
			result += 1;
		else if (tmp != 0) {
			result += vecP[i] * tmp;
			tmp = 0;
		}
		else
			tmp = vecP[i];
	}
	if (tmp != 0) {
		result += tmp;
		tmp = 0;
	}
	for (int i = 0; i < vecM.size(); i++) {
		if (tmp != 0) {
			result += vecM[i] * tmp;
			tmp = 0;
		}
		else
			tmp = vecM[i];
	}
	if (tmp != 0 && !isZero)
		result += tmp;
	cout << result;

	return 0;
}
