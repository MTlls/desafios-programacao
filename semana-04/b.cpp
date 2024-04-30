#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(ushort a, ushort b) const {
		return a > b;
	}
};

struct cmp2 {
	bool operator()(const ushort a, const ushort b) const {
		return a < b;
	}
};

int main() {
	uint vacas, leite, paciencia;
	unsigned long long soma = 0;
	cin >> vacas;

	map<uint, multiset<ushort, cmp>> tempos;
	priority_queue<ushort, vector<ushort>, cmp2> atual;

	for(uint i = 0; i < vacas; i++) {
		cin >> leite >> paciencia;

		if(auto fila = tempos.find(paciencia); fila == tempos.end()) {
			multiset<ushort, cmp> nova_fila;

			nova_fila.insert(leite);
			tempos.insert(make_pair(paciencia, nova_fila));

		} else {
			(*fila).second.insert(leite);

			if((*fila).second.size() > paciencia) {
				(*fila).second.erase(--(*fila).second.end());
			}
		}
	}

	uint maior_paciencia = (--tempos.end())->first;
	auto it = prev(tempos.end());

	for(uint i = maior_paciencia; i > 0; i--) {
		if(!tempos.empty() && i == it->first) {
			for(auto elem : (*it).second) {
				atual.push(elem);
			}

			if(tempos.size() != 1) {
				auto aux_it = prev(it);
				tempos.erase(it);
				it = aux_it;
			} else {
				tempos.erase(it);
			}
		}

		if(!atual.empty()) {

			soma += atual.top();
			atual.pop();
		}
	}

	cout << soma << "\n";
	return 0;
}
