#include <bits/stdc++.h>
using namespace std;

bool cmp_concatenacao(string a, string b) {
	return a + b < b + a;  // ordem lexicografica concatenada
}

int main() {
	int n;

	string palavra;

	cin >> n;

	multiset<string, decltype(cmp_concatenacao)*> palavras(cmp_concatenacao);

	for(int i = 0; i < n; i++) {
		cin >> palavra;

		palavras.insert(palavra);
	}


	auto it = palavras.begin();
	
	// imprime as palavras
	for(; it != palavras.end(); it++) {
		cout << (*it);

	}
		cout << " \n";

	return 0;
}