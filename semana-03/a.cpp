#include <bits/stdc++.h>
using namespace std;

int n, qntd_restricoes;
vector<int> livros(12);
vector<bool> escolhidos(12);

void gen(int geracao, unordered_map<int, vector<int>> &restricoes) {
	if(geracao == n) {
		for(int i = 0; i < n; i++) {
			cout << livros[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = 1; i <= n; i++) {
		// cout << "laço linha 17: i: " << i << "\n";
		if(!escolhidos[i]) {
			escolhidos[i] = 1;
			// cout << "escolhidos[" << i << "]: " << 1 << ".\n\n";
			livros[geracao] = i;
			for(int i = 0; i < n; i++) {
				// cout << livros[i] << " ";
			}
			// cout << "\n";
			if(auto restricoes_x = restricoes.find(livros[geracao]); restricoes_x != restricoes.end()) {
				for(auto y : (*restricoes_x).second) {
					// cout << "verificando se " << i << " esta a frente de " << y << ".\n";
					for(int j = geracao; j >= 0; j--) {
							// cout << "testando se " << livros[j] << " esta a frente de " << y << ".\n";
						if(livros[j] == y) {
							escolhidos[i] = 0;
							return;
						}
					}
				}
			}
			// cout << "entrando em gen("<< geracao+1 << ")\n\n";

			gen(geracao + 1, restricoes);
			// cout << "escolhidos[" << i << "]: " << 0 << "\n\n";

			escolhidos[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;

	cin >> n >> qntd_restricoes;
	bool interrompido = false;

	unordered_map<int, vector<int>> restricoes(qntd_restricoes);
	for(int i = 0; i < 12; i++) escolhidos[i] = 0;
	// restricoes
	for(int i = 0; i < qntd_restricoes; i++) {
		cin >> a >> b;
		// insere na hash o valor b na lista respectiva da chave a
		// visualmente seria como...
		// <a, lista_menores> = < a, b1 -> b2-> b3 ...>
		if(auto anterior = restricoes.find(a); anterior != restricoes.end()) {
			((*anterior).second).push_back(b);
		} else {
			vector<int> lista = {b};
			restricoes.insert(make_pair(a, lista));
		}
	}

	// // Imprimir os valores dentro de restricoes e suas respectivas listas
	// // for(const auto& entry : restricoes) {
	// // 	cout << "Chave: " << entry.first << ", Lista: ";
	// // 	for(const auto& value : entry.second) {
	// // 		cout << value << " ";
	// // 	}
	// // 	cout << endl;
	// // }

	// do {
	// 	interrompido = false;
	// 	for(auto x : livros) {
	// 		// cout << "testando a permutacao ";
	// 		// for(auto z : livros) {
	// 		// 	cout << z << " ";
	// 		// }
	// 		// cout << "\n";
	// 		// se existe alguma restricao pra x
	// 		if(auto restricoes_x = restricoes.find(x); restricoes_x != restricoes.end()) {
	// 			// cout << "achou alguma restricao pra " << (*restricoes_x).first << "\n";
	// 			// procura se ja foi inserido os valores restringidos
	// 			// x tem de vir antes de y1, y2, y3...
	// 			for(auto y : (*restricoes_x).second) {
	// 				// cout << "verificando se o " << y << " esta antes de " << (*restricoes_x).first << "\n";
	// 				// se achamos, paramos de criar essa combinacao por ai!
	// 				if(inseridos.end() != inseridos.find(y)) {
	// 					// cout << "pulando essa permutacao\n";
	// 					inseridos.clear();
	// 					interrompido = true;
	// 					break;
	// 				}
	// 			}
	// 		}

	// 		// para sair do loop externo e ir para a proxima permutacao
	// 		if(interrompido)
	// 			break;

	// 		inseridos.insert(x);
	// 	}
	// 	if(interrompido) {
	// 		inseridos.clear();
	// 		continue;
	// 	}
	// 	// cout << "terminou a permutacao\n";
	// 	for(auto z : livros) {
	// 		cout << z << " ";
	// 	}
	// 	inseridos.clear();
	// 	cout << "\n";
	// } while(next_permutation(livros.begin(), livros.end()));

	gen(0, restricoes);
	return 0;
}