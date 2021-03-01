#include <iostream>

using namespace std;
int scores[100001];
int main() {

	int a, b, T, N, cnt, meet;

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			scores[a] = b;
		}
		cnt = 1;
		meet = scores[1];
		for (int i = 2; i <= N; i++) {
			if (scores[i] < meet) {
				cnt++;
				meet = scores[i];
			}
		}
		cout << cnt << endl;
	}

	return 0;
}