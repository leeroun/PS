#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {

	vector<pair<int, int>> Ecows, Ncows;
	vector<bool> SequenceE;
	int n, x, y;
	char facing;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> facing >> x >> y;
		if (facing == 'E')
		{
			SequenceE.push_back(true);
			Ecows.push_back(make_pair(x, y));
		}
		else 
		{
			SequenceE.push_back(false);
			Ncows.push_back(make_pair(x, y));
		}
	}
	int eIndex = 0, nIndex = 0, d_x, d_y, ret;

	for (int i = 0; i < n; ++i) {
		ret = 1000000000;
		if (SequenceE[i]) {
			for (int j = 0; j < Ncows.size(); ++j) {
				d_x = Ncows[j].first - Ecows[eIndex].first;
				d_y = Ecows[eIndex].second - Ncows[j].second;
				cout << d_x << " " << d_y<<endl;
				if ((d_x > 0 && d_y > 0) && d_x > d_y)
					ret = (ret < d_x) ? ret : d_x;
			}
			if (ret == 1000000000)
				cout << "Infinity\n";
			else
				cout << ret << endl;
			++eIndex;
		}
		else {
			for (int j = 0; j < Ecows.size(); ++j) {
				d_x = Ncows[nIndex].first - Ecows[j].first;
				d_y = Ecows[j].second - Ncows[nIndex].second;
				cout << d_x << " " << d_y << endl;
				if ((d_x > 0 && d_y > 0) && d_x < d_y)
					ret = (ret < d_y) ? ret : d_y;
			}
			if (ret == 1000000000)
				cout << "Infinity\n";
			else
				cout << ret << endl;
			++nIndex;
		}
	}
	//중간에 멈추는 경우를 생각안했다!

	return 0;
}