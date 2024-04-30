#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
	int n = 1;
	ull mask = 1, a, b, multiplos = 1, qntd_kalimos = 0;

	cin >> a >> b >> n;

	vector<ull> primos(n);

	for(int i = 0; i < n; i++) {
		cin >> primos[i];
	}

	for(int sinal = 0; mask < (1 << n); mask++) {
		multiplos = 1, sinal = 0;
		for(int i = 0; i < n; i++) {
			if((mask & (1 << i)) != 0) {
				sinal++;
				multiplos *= primos[i];
			}
		}

		multiplos = (b / multiplos) - ((a - 1) / multiplos);
		

		if((sinal & 1) != 0) {
			qntd_kalimos += multiplos;
		} else {
			qntd_kalimos -= multiplos;
		}
	}


	cout << (b - a + 1) - qntd_kalimos << "\n";
	return 0;
}