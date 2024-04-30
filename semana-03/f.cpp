#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	unsigned long long x, menor = INT64_MAX;

	cin >> n;

	multiset<unsigned long long> numeros;
	vector<unsigned long long> fatores(n - 1);

	// insere ordenadamente os valores
	for(int i = 0; i < n; i++) {
		cin >> x;
		numeros.insert(x);
	}

	auto atual = numeros.begin();
	auto anterior = atual++;

	// se o fator for 1...
	if((*atual) / (*anterior) == 1) {
		cout << (*atual) << "\n";
		return 0;
	}

	// verifica os fatores entre cada valor
	for(int i = 0; i < n - 1; atual++, anterior++, i++) {
		fatores[i] = (*atual) / (*anterior);

		if(fatores[i] < menor) menor = fatores[i];
	}

	// vou atualizar o iterador para nao haver aumento no tempo de busca
	atual = numeros.begin();
	for(int i = 0; i < n - 1; i++, atual++) {
		if(menor != fatores[i]) {
			cout << (*atual * menor) << "\n";
			return 0;
		}
	}

	// se nao foi achado nenhuma inconsistencia, o numero faltante esta no inicio ou no fim, eh impresso os possiveis valores.
	auto comeco = numeros.begin(), fim = --numeros.end();
	
	if(*comeco % menor == 0)
		cout << (*comeco / menor) << "\n";

	cout << (*(fim) * menor)<< "\n";
	return 0;
}
