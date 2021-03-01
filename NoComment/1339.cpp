//±×¸®µð
//Gold 5
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {

	int alphas[26] = { 0, };
	string s;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			alphas[s[j] - 'A'] += pow(10, s.size() - j) / 10;
		}
	}
	sort(alphas, alphas + 26);

	int num = 9, result = 0;
	for (int i = 25; i >= 16; --i) {
		result += alphas[i] * num--;
	}
	cout << result;
	return 0;
}
