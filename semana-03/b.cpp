#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, diff = INT_MAX, pilha1 = 0, pilha2 = 0;
	// um n multiplicado pelo seu antecessor sempre é par, por isso int
	int possibilidades, qntd_bits;

	cin >> n;
	vector<int> pedras(n);

	possibilidades = (n * (n - 1)) / 2;
	// insere as pedras
	for(int i = 0; i < n; i++) cin >> pedras[i];

	// cout << possibilidades << "possibilidades.\n";
	for(int i = 0; i < (1 << n); i++) {
		pilha1 = 0, pilha2 = 0;

		for(int j = i, k = 0; k < n; k++) {
			// se o j-ésimo bit estiver aceso, vai para a pilha 1, cc 2
			if((j & (1 << k)) != 0) {
                // cout << "inserindo o " << pedras[k] << " na pilha 1\n";
				pilha1 += pedras[k];
			} else {
                // cout << "inserindo o " << pedras[k] << " na pilha 2\n";
				pilha2 += pedras[k];
			}
			// cout << "pedras[k]: " << pedras[k] << "\npilha1:" << pilha1 << "\npilha2:" << pilha2 << "\n j:" << j << "\n";
		}

		if(diff > abs(pilha1 - pilha2)) diff = abs(pilha1 - pilha2);
		// cout << "diff:" << diff << "\nfim do loop\n\n";
	}
	cout << "diff: " << diff;

	return 0;
}