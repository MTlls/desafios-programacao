#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n, tam, qntd, ai, inicio, fim;
	ll valor, soma = 0;

	cin >> n >> qntd >> tam;

	vector<ll> prefixos(n + 1);
	vector<int> numeros(n);
	vector<vector<int>> dp(qntd + 1, vector<int>(n + 2, 0));

	prefixos[0] = 0;

	if(tam * qntd == n) {
		cout << "0\n";
		return 0;
	}

	for(int i = 0; i < n; i++) {
		cin >> ai;

		numeros[i] = ai;
		soma += ai;

		prefixos[i + 1] = prefixos[i] + numeros[i];
	}

	for(int i = 0; i < n; i++) {
		dp[0][i] = prefixos[i];
	}

	for(int i = 1; i <= qntd; i++) {
		for(int j = tam; j < n + 1; j++) {
			// cout << "numero de quadrados atual: " << j << "\nnumero de lapis: " << i << "\n";

			// se o numero de posicoes ter o tamanho de i lapises concatenados, ele tera
			if(j == i * tam)
				dp[i][j] = 0;
			// se o tamanho de lapis que serao ocupados for > que o numero atual de posicoes, usaremos a pontuação com i-1 lapis anterior para a mesma posicao
			else if(tam * i > j)
				dp[i][j] = dp[i - 1][j];
			// caso contrario, comparamos se vale a pena inserir mais um quadrado ou cobrir com mais um lapis
			else
				dp[i][j] = max(dp[i][j - 1] + numeros[j - 1], dp[i - 1][j - tam]);

		}

	}

	cout << dp[qntd][n] << "\n";

	return 0;
}