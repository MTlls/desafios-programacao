#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    vector<int> moedas = {1,5,10,25,50};

    vector<unsigned long long> modos(3e4, 0);
    // ha apenas um modo de organizar o valor 0
    modos[0] = 1;
    
    // para cada moeda, "incrementa um modo novo de organizar o valor n"
    for (auto moeda : moedas) {
        // a cada vez que voce calcula o valor do i-esimo valor da dp, voce incrementa o (valor) com o (valor - moeda), que eh o troco restante e na dp o indice (valor - moeda) ja guarda a quantidade de moedas necessarias.
        // meio que eh modos[valor] += modos[valor - moeda da vez]
        for (int i = moeda; i <= 3e4; i++)
            modos[i] += modos[i - moeda];
    }
    while(cin >> n){
        cout << modos[n] << "\n";
    }
    return 0;
}