#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using us = unsigned short;

int main() {
	us menu_qntd, porcoes_necessarias, regras_qntd, aux, ant, pos;
	uint32_t ai, next_mask;
	ll satisf_max = 0, ganho = 0;

	// esse vetor sera a nossa dp
	// é uma matriz de dimensões [2^18][18]
	// sendo cada linha uma mascara que indica quais pratos foram comidos e um número de 1 a 18 indicando qual foi a ultima comida (isso gera muitos espaços em branco na matriz)
	vector<vector<ll>> dp((1 << 18), vector<ll>(19, -1));
	// um map que guardamos as regras
	map<pair<us, us>, ll> regras;

	// N, M e K
	cin >> menu_qntd >> porcoes_necessarias >> regras_qntd;
	// um vector nos quais é guardado o valor de cada satisfação por prato
	vector<ll> satisfacoes(menu_qntd);

	// inserção das satisfacoes por prato
	for(us i = 0; i < menu_qntd; i++) {
		cin >> ai;
		// 0001, 0010, 0100, 1000...
		dp[1 << i][i + 1] = ai;
		satisfacoes[i] = ai;
	}


	// se for apenas uma porção que kefa irá comer, apenas pega o máximo das satisfações
	if(porcoes_necessarias == 1) {
		satisf_max = *max_element(satisfacoes.begin(), satisfacoes.end());
		cout << satisf_max << "\n";
		return 0;
	}

	// insere as regras aqui
	for(us i = 0; i < regras_qntd; i++) {
		cin >> ant >> pos >> ganho;
		regras.insert(make_pair(make_pair(ant, pos), ganho));
	}

	// enumerando as máscaras
	for(uint32_t mask = 1; mask < (1 << menu_qntd); mask++) {
		// para cada combinação de pratos, combina o penultimo com o ultimo
		for(us ultimo = 0; ultimo < menu_qntd; ultimo++) {
			if(dp[mask][ultimo + 1] == -1) {
				continue;
			}

			// vai mudando todas as mascaras acrescentando mais um digito, e testa para o novo ultimo qual opção é melhor:
			// adicionar o último prato + mascara anterior ou
			// manter o valor do ultimo prato + nova máscara, que é possível passar pelo mesmo valor mais de uma vez.
			for(us next_ultimo = 0; next_ultimo < menu_qntd; next_ultimo++, ganho = 0) {
				// 0010 | 0010 = 0010, então não precisa fazer essa iteração
				if(mask & (1 << next_ultimo))
					continue;

				next_mask = mask | (1 << next_ultimo);
				
				// caso exista a regra, a salva em "ganho"
				if(auto achado = regras.find(pair<us, us>(ultimo + 1, next_ultimo + 1)); achado != regras.end()) {
					ganho = (*achado).second;
				}

				// caso não tenha sido escrito nessa área
				if(dp[next_mask][next_ultimo + 1] == -1)
					dp[next_mask][next_ultimo + 1] = 0;

				// aqui é a troca de estado da dp.
				dp[next_mask][next_ultimo + 1] = max((dp[next_mask][next_ultimo + 1]), (dp[mask][ultimo + 1] + satisfacoes[next_ultimo] + ganho));

				// a satisfação máxima atual é a maior valor indexado em [quantidade de bits 1 = porcoes que serão comidas][1..n]
				if(__builtin_popcount(next_mask) == porcoes_necessarias)
					satisf_max = max(satisf_max, dp[next_mask][next_ultimo + 1]);
			}
		}
	}
	cout << satisf_max << "\n";
	return 0;
}