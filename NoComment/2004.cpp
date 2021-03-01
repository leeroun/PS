#include <iostream>
#include <algorithm>

using namespace std;

void divide2(long long num, long long& div2){
	for (long long i = 2; i <= num; i *= 2)
		div2 += num / i;
}
void divide5(long long num, long long& div5) {
	for (long long i = 5; i <= num; i *= 5)
		div5 += num / i;
}
int main() {
	long long n, m;
	long long ndiv2 = 0, ndiv5 = 0, mdiv2 = 0, mdiv5 = 0, nmdiv2 = 0, nmdiv5 = 0;

	cin >> n >> m;

	divide2(n, ndiv2);
	divide5(n, ndiv5);
	divide2(n-m, nmdiv2);
	divide5(n-m, nmdiv5);
	divide2(m, mdiv2);
	divide5(m, mdiv5);


	cout << min((ndiv2 - nmdiv2 - mdiv2), (ndiv5 - nmdiv5 - mdiv5)) << endl;

	return 0;
}  
