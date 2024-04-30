#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
    aqui a ideia eh montar a igualdade d(f + e) = ab + c,
    permutando por todos os elementos em S.

    precisamos dizer que existe um resultado de um lado das igualdades, depois verificamos se para o outro lado existe tambem e somamos como umm resultado a mais.

    Usamos um map para isso.
*/
int main() {
	int n, x;
	ll total = 0;

	map<ll, int> igualdade;
	cin >> n;
	vector<int> valores;

	for(int i = 0; i < n; i++) {
		cin >> x;
		valores.push_back(x);
	}
    // for(auto val : valores) {
    //     cout << val << " ";
    // }
    // cout << endl;
	// agora inserimos o lado esquerdo da igualdade no map, se há um resultado, incrementamos a posicao em 1
	// d(e + f)
	for(auto d : valores)
		for(auto f : valores)
			for(auto e : valores) {
				if(d != 0) {
					igualdade[d * (e + f)]++;
					// cout << "inseriu " << d << " * (" << e << " + " << f << ")"
					//      << " = "<<d * (e + f) << "\n";
				}
			}

	// verificamos o lado direito, se há um resultado nessa posicao "roubamos" uma unidade da posicao
	// ab + c
	for(auto a : valores)
		for(auto b : valores)
			for(auto c : valores)
				if(auto valor = igualdade.find(((a * b) + c)); valor != igualdade.end()) {
					// cout << "achou (" << a << " * " << b << ") + " << c << ""
					    //  << " =  " << (*valor).first << "\n";
					total += (*valor).second;
				}

	cout << total << "\n";
	return 0;
}