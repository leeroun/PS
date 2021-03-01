#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int P, L, V;
	int result, caseCnt = 1;
	while (true)
	{
		cin >> L >> P >> V;
		if (!L)
			break;
		result = (V / P) * L + min(V % P, L);
		cout << "Case " << caseCnt++ << ": "<< result << endl;
	}

	return 0;
}