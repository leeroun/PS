#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, K, W, V;
vector<pair<int, int>> v;
int dp[101][100001];

int main() {
	int result = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> W >> V;
		v.push_back(make_pair(W, V));
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j < v[i - 1].first) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i - 1].first] + v[i - 1].second);
			}
		}
	}


	cout << dp[N][K] << endl;


	return 0;
}