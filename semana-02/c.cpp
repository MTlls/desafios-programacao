#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ll n, numero, rodadas = 0;

	set<ll> numeros;

    cin >> n;
    // o numero de rodadas soh eh incrementado se o seu antecessor nao estiver nos numeros ja apresentados, funciona com 1 pois pelo menos tera uma rodada.
	for(ll i = 0; i < n; i++) {
		cin >> numero;

		if(numeros.find(numero - 1L) == numeros.end()) rodadas++;
        
        numeros.insert(numero);
	}

    cout << rodadas << "\n";
	return 0;
}