#include <bits/stdc++.h>
using namespace std;

inline void makeBurger(int *ganhos, int *preco, int *paes, int *ingredientes) {
	// se a qntd de ingrediente >= duplas de pães
	if(*ingredientes >= (*paes / 2)) {
		// quantidade feita de AcBurger
		//cout << "fazendo " << (*paes / 2) << " AcBurgers\n";
		*ganhos += ((*paes / 2) * (*preco));
		*ingredientes -= (*paes / 2);
		*paes = 0;
	} else {
		//cout << "fazendo " << 2 * (*ingredientes) << " AcBurgers\n";
		*ganhos += ((*ingredientes) * (*preco));
		*paes -= (2 * (*ingredientes));
		*ingredientes = 0;
	}
}

int main() {
	int n, p, h, f, d, c, sum = 0;
	cin >> n;
	vector<vector<int>> testes(n, vector<int>(5));

	for(int i = 0; i < n; i++) {
		sum = 0;
		cin >> p >> h >> f >> d >> c;

		///////////////////////
    
		// enquanto houver pao disponível
		while(p >= 2 && (h != 0 || f != 0)){
			// se  AcCheddar > AcChicken
			if(d > c) {
				if(h > 0) {
					// quantidade feita de AcCheddar
					//cout << "fazendo AcCheddar\n";
					makeBurger(&sum, &d, &p, &h);
				} else if(f > 0) {
					//cout << "fazendo AcChicken\n";
					// quantidade feita de AcChicken
					makeBurger(&sum, &c, &p, &f);
				}
			} else {
				if(f > 0) {
					// quantidade feita de AcChicken
					//cout << "fazendo AcChicken\n";
					makeBurger(&sum, &c, &p, &f);
				} else if(h > 0) {
					// quantidade feita de AcCheddar
					//cout << "fazendo AcCheddar\n";
					makeBurger(&sum, &d, &p, &h);
				}
			}
		}

		cout << sum << "\n";
	}

	return 0;
}