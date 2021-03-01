#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 987654321;

vector<pair<int, int>> nodes[20001];
int V, E, K, u, v, w;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> V >> E;
	cin >> K;
	
	while (E--) {
		cin >> u >> v >> w;
		nodes[u].push_back(make_pair(v, w));
	}

	vector<int> dist(V + 1, INF);
	dist[K] = 0;

	priority_queue<pair<int, int>> que;
	que.push(make_pair(0, K));

	while (!que.empty()) {
		int curCost = -que.top().first;
		int curPos = que.top().second;
		que.pop();

		if (dist[curPos] < curCost)
			continue;

		for (int i = 0; i < nodes[curPos].size(); i++) {
			int nextPos = nodes[curPos][i].first;
			int nextCost = nodes[curPos][i].second;

			if (dist[nextPos] > curCost + nextCost)
			{
				dist[nextPos] = curCost + nextCost;
				que.push(make_pair(-dist[nextPos], nextPos));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n" ;
		else
			cout << dist[i] << "\n";
	}

	return 0;
}