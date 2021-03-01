#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	int k, input, result = 0;
	stack<int> s;

	cin >> k;
	while (k--) {
		cin >> input;
		if (input == 0)
			s.pop();
		else {
			s.push(input);
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	cout << result;

	return 0;
}
