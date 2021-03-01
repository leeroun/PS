#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int input, a, i, j;

	bool isPrime[1000001];

	for (i = 1; i < 1000000; i++)
		isPrime[i] = true;
	for (i = 2; i <= sqrt(1000000); i++)
		for (j = i + i; j <= 1000000; j += i)
			if (isPrime[j]) isPrime[j] = false;

	while(true) {
		scanf("%d", &input);
		if (!input)
			break;
		for (i = 3; i <= input / 2; i+=2) {
			if (isPrime[i] && isPrime[input - i]) {
				printf("%d = %d + %d\n", input, i, input - i);
				break;
			}
		}
		if (i > input)
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}