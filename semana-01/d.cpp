#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, prox, ant, movimentos = 0, diff;

    cin >> n;

    cin >> ant;
    for (int i = 0; i < n - 1; i++) {
        cin >> prox;
        if(ant > prox)
            diff = ant - prox;
        else 
            diff = 0;
        
        movimentos += diff;
        ant = prox + diff;
    }

    cout << movimentos << "\n";
    return 0;
}
