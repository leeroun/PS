#include <iostream>

using namespace std;

int main() {

	int Bmoney, Tmoney;
	int BNP = 0, TIMING = 0;
	int days[14];

	cin >> Bmoney;
	Tmoney = Bmoney;

	for (int i = 0; i < 14; i++) {
		cin >> days[i];
	}

	int chk = 0;

	BNP = Bmoney / days[0];
	Bmoney = Bmoney % days[0];

	for (int i = 1; i < 14; i++) {
		if (chk >= 0 && days[i] < days[i - 1])
			chk = -1;
		else if (chk <= 0 && days[i] > days[i - 1])
			chk = 1;
		else if (chk > 0 && days[i] > days[i - 1])
			++chk;
		else if (chk < 0 && days[i] < days[i - 1])
			--chk;
		else
			chk = 0;

		BNP += Bmoney / days[i];
		if (Bmoney / days[i] > 0)
			Bmoney = Bmoney % days[i];

		if (chk <= -3) {
			TIMING += Tmoney / days[i];
			if (Tmoney / days[i] > 0)
				Tmoney = Tmoney % days[i];
		}
		else if (chk >= 3) {
			Tmoney += TIMING * days[i];
			TIMING = 0;
		}
	}

	Bmoney += BNP * days[13];
	Tmoney += TIMING * days[13];

	if (Bmoney > Tmoney)
		cout << "BNP" << endl;
	else if (Tmoney > Bmoney)
		cout << "TIMING" << endl;
	else
		cout << "SAMESAME" << endl;
	return 0;
}
