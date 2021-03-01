#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int T, f, s, result;
	cin >> T;

	while (T--) {
		cin >> f >> s;
		result = 0;
		
		if (f == 0)
			result += 0;
		else if (f <= 1)
			result += 500;
		else if (f <= 3)
			result += 300;
		else if (f <= 6)
			result += 200;
		else if (f <= 10)
			result += 50;
		else if (f <= 15)
			result += 30;
		else if (f <= 21)
			result += 10;

		if (s == 0)
			result += 0;
		else if (s <= 1)
			result += 512;
		else if (s <= 3)
			result += 256;
		else if (s <= 7)
			result += 128;
		else if (s <= 15)
			result += 64;
		else if (s <= 31)
			result += 32;
		
		cout << result*10000 << endl;
	}


	return 0;
}