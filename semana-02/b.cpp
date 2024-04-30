#include <bits/stdc++.h>

using namespace std;

int main() {
	// A = tamanho
	// L para Leste, O para Oeste
	stack<pair<int, char>> pilha;
	int n, alt;
	char direcao;

	cin >> n;

	if(n % 2 != 0) {
		cout << "N\n";
		return 0;
	}

	for(int i = 0; i < n; i++) {
		cin >> alt >> direcao;
		if((pilha.empty() && direcao == 'O') ||
		   (!(pilha.empty()) &&
		    ((pilha.top().first < alt) ||
		     (pilha.top().first == alt && pilha.top().second == direcao) ||
		     (pilha.top().first > alt && direcao == 'O')))) {
			cout << "N\n";
			return 0;
		}
		// insere ou achou ponte
		else {
			if(direcao == 'O') {
				pilha.pop();
			} else {
				pilha.push(make_pair(alt, direcao));
			}
		}
	}
	if(pilha.empty())
		cout << "S\n";
	else
		cout << "N\n";
	return 0;
}