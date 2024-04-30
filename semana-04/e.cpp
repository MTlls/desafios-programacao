#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long x = 0, y = 0, a = 0, b = 0, c = 0, gostosura, maior_vermelho, maior_verde, maior_cores, maior_sem_cor, maior, soma = 0;

	cin >> x >> y >> a >> b >> c;
	multiset<unsigned long long> vermelhos, verdes, sem_cor;

	// vermelho = 0, verde = 1, sem cor = -1

	for(unsigned long long i = 0; i < a; i++) {
		cin >> gostosura;
		vermelhos.insert(gostosura);
		// se já enviamos os x maiores, não vamos usar mais do que x maçãs
		if(x <= i) {
			vermelhos.erase(vermelhos.begin());
		}
	}
	for(unsigned long long i = 0; i < b; i++) {
		cin >> gostosura;
		verdes.insert(gostosura);
		// se já enviamos os y maiores, não vamos usar mais do que y maçãs
		if(y <= i) {
			verdes.erase(verdes.begin());
		}
	}

	for(unsigned long long i = 0; i < c; i++) {
		cin >> gostosura;
		sem_cor.insert(gostosura);
	}

	// sort(vermelhos.rbegin(), vermelhos.rend());
	// sort(verdes.rbegin(), verdes.rend());
	// sort(sem_cor.rbegin(), sem_cor.rend());

	// cout << "vermelhos: ";
	// for(int i = 0; i < a; i++) {
	// 	cout << vermelhos[i] << " ";
	// }
	// cout << "\n"
	//      << "verdes:    ";
	// for(int i = 0; i < b; i++) {
	// 	cout << verdes[i] << " ";
	// }

	// cout << "\n";

	// cout << "sem cor:    ";

	// for(int i = 0; i < c; i++) {
	// 	cout << sem_cor[i] << " ";
	// }
	// cout << "\n";
	while((x > 0 && y > 0)) {
		// tem que verificar se não está vazio, senão é segfault
		maior_vermelho = vermelhos.empty() ? 0 : *vermelhos.rbegin();
		maior_verde = verdes.empty() ? 0 : *verdes.rbegin();
		maior_sem_cor = sem_cor.empty() ? 0 : *sem_cor.rbegin();
		maior_cores = max(maior_vermelho, maior_verde);
		maior = max(maior_cores, maior_sem_cor);
		if (maior == maior_sem_cor){
			if(*vermelhos.begin() < *verdes.begin()) {
				// nao vamos usar a menor maçã agora.
				vermelhos.erase(vermelhos.begin());

				x--;
			} else {
				// nao vamos usar a menor maçã agora.
				verdes.erase(verdes.begin());

				y--;
			}

			sem_cor.erase(--sem_cor.end());
		}
		// maior é vermelho
		else if(maior == maior_vermelho) {
			// cout << "escolhido uma maçã vermelha\n";

			vermelhos.erase(--vermelhos.end());
			x--;
		}  // maior é verde
		else if(maior == maior_verde) {
			// cout << "escolhido uma maçã verde\n";

			verdes.erase(--verdes.end());
			y--;
		}  // maior n tem cor

		soma += maior;
	}

	while(x > 0) {
		maior_vermelho = vermelhos.empty() ? 0 : *vermelhos.rbegin();
		maior = max(maior_vermelho, sem_cor.empty() ? 0 : *sem_cor.rbegin());

		if(maior == maior_vermelho) {
			vermelhos.erase(--vermelhos.end());
		} else {
			// nao vamos usar a menor maçã agora.
			vermelhos.erase(vermelhos.begin());

			sem_cor.erase(--sem_cor.end());
		}

		x--;
		soma += maior;
	}
	while(y > 0) {
		maior_verde = verdes.empty() ? 0 : *verdes.rbegin();
		maior = max(maior_verde, sem_cor.empty() ? 0 : *sem_cor.rbegin());
		if(maior == maior_verde) {
			verdes.erase(--verdes.end());
		} else {
			verdes.erase(verdes.begin());
			sem_cor.erase(--sem_cor.end());
		}

		y--;
		soma += maior;
	}

	cout << soma << "\n";
	return 0;
}