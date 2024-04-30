#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
    long long meio = 0;
    long double mediana = 0, sum = 0;
	multiset<int> valores;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> x;

		valores.insert(x);
	}

    meio = valores.size() / 2;

    auto it_next = valores.begin();
    advance(it_next, meio);

    if(valores.size() % 2 == 0) {
        auto it = it_next;
        mediana = (*it_next + *(--it)) / 2.0;
        // cout << "it = " << *it << "\nit_next = " << *it_next<< "\n";
    }
    else {
        mediana = *it_next;
    }

    // cout << "mediana: " << mediana << "\n";
    for (auto i = valores.begin(); i != valores.end(); i++) {
        sum += (fabs((*i) - mediana));
    }

    cout << (long long)floor(sum) << "\n";

	return 0;
}