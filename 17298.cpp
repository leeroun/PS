#include <iostream>
#include <stack>
using namespace std;
int result[1000000];

int main() {

	stack<int> input_s;
	stack<int> max_s;

	int n, input;

	cin >> n;
	while (n--) {
		cin >> input;
		input_s.push(input);
	}

	int tmp, tmp2, t = 0;
	while (!input_s.empty()) {
		tmp = input_s.top();
		input_s.pop();
		
		if (max_s.empty()) {
			result[t++] = -1;
			max_s.push(tmp);
		}
		else {
			while (true)
			{
				if (max_s.empty()) {
					result[t++] = -1;
					max_s.push(tmp);
					break;
				}
				tmp2 = max_s.top();
				if (tmp2 > tmp)
				{
					result[t++] = tmp2;
					max_s.push(tmp);
					break;
				}
				else {
					max_s.pop();
				}
			}
		}
	}

	for (t -= 1; t >= 0; t--)
		cout << result[t] << " ";

	return 0;
}