#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<bool> passados(20);
ll menor = LONG_LONG_MAX;

void gerador_intervalo(vector<ll> &valores, ll geracao) {
	// ocorre apenas no final do vetor
	if(geracao == (valores.size() - 1)) {
		
		ll valores_or = valores[0], resultado = 0;

		// cout << "caso [";
		for(int i = 1; i < valores.size(); i++) {
			// cout << valores[i-1];
			// aqui, troca-se de intervalo
			if(passados[i-1] == true) {
				resultado ^= valores_or;
				
				// eh preciso guardar o comeco do novo intervalo
				// se houver outra troca de intervalo no proximo valor, precisa estar guardado
				valores_or = valores[i];
				// cout << "][";
			}
			// aqui, mantem o intervalo
			else {
				valores_or |= valores[i];
				// if (i != valores.size()) cout << ",";
			}
		}

		// eh necessario um ultimo XOR (sabemos onde o ultimo intervalo termina e eh no final)
		resultado ^= valores_or;
		// cout << valores.back() <<"]\n";
		// atualiza o resultado atual
		if(menor > resultado)
			menor = resultado;

		// cout << "o menor atual é " << menor << "\n\n";
		return;
	}
	// cout << "a \n";

	// altera os valores geracionais, para criar as possiveis combinacoes
	passados[geracao] = false;
	gerador_intervalo(valores, geracao + 1);
	// aqui comeca a ocorrer XORs
	passados[geracao] = true;
	gerador_intervalo(valores, geracao + 1);
}

int main() {
	int n;

	cin >> n;
	vector<ll> valores(n);

	// insere os valores
	for(int i = 0; i < n; i++) {
		cin >> valores[i];
		passados[i] = false;
	}

	gerador_intervalo(valores, 0);

	cout << menor << "\n";
	return 0;
}