#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	string inputString;
	int index = 0;
	bool tag = false;
	vector<char> word;

	getline(cin, inputString);

	while (inputString[index] != '\0') {
		if (tag) {
			if (inputString[index] == '>') {
				tag = false;
			}
			cout << inputString[index];
		}
		else if (inputString[index] == '<') {
			reverse(word.begin(), word.end());
			for (auto& a : word)
				cout << a;
			word.clear();
			tag = true;
			cout << inputString[index];
		}
		else if(inputString[index] == ' '){
			reverse(word.begin(), word.end());
			for (auto& a : word)
				cout << a;
			word.clear();
			cout << " ";
		}
		else {
			word.push_back(inputString[index]);
		}
		index++;
	}
	reverse(word.begin(), word.end());
	for (auto& a : word)
		cout << a;



	return 0;
}
