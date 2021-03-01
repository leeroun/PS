#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;
	bool isPlus = true;
	int result = 0;
	int currentNum = 0;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '+' || input[i] == '-') {
			if (isPlus) {
				result += currentNum;
				currentNum = 0;
			}
			else {
				result -= currentNum;
				currentNum = 0;
			}
			if (input[i] == '-')
				isPlus = false;
		}
		else {
			if (currentNum == 0) 
				currentNum = (int)input[i] - 48;
			else
			{
				currentNum *= 10;
				currentNum += (int)input[i] - 48;
			}
		}
	}
	if (isPlus) {
		result += currentNum;
		currentNum = 0;
	}
	else {
		result -= currentNum;
		currentNum = 0;
	}
	cout << result << endl;

	return 0;
}
