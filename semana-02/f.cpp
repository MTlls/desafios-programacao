#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ll n, vezes, valor;
	char op;

	list<int> fita;

	auto cabeca = fita.begin();
	auto ant = cabeca;

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> op;

		if(op == 'i') {
			cin >> vezes >> valor;

			ant = cabeca;
			ant--;
			// cout << "inserindo o valor " << valor << " " << vezes << " vezes\n";
			for(int i = 0; i < vezes; i++) fita.insert(cabeca, valor);

			if(vezes != fita.size()) cabeca = ant;

			cabeca++;
		} else if(op == 'm') {
			cin >> vezes;

			// cout << "movendo a cabeca "<< vezes << " vezes\n";
			if(vezes > 0){
				for(int i = 0; i < vezes; i++) cabeca++;}
			else{
				for(int i = 0; i < vezes * -1; i++) cabeca--;}
		} else if(op == 'd') {
			// cout << "eliminando a cabeça..." << "\n";
            cabeca = fita.erase(cabeca);
		} else{
			cout << *cabeca << "\n";
        }

		// for(auto it = fita.begin(); it != fita.end(); ++it) {
		// 	cout << *it << " ";
		// }
		// cout << "\n";
		// for(auto it = fita.begin(); it != fita.end(); ++it) {
        //     if(it == cabeca)
		// 		cout << "^";
		// 	else
		// 		cout << "  ";
		// }
        // cout << "\n";
	}

	return 0;
}