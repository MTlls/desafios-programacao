#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

map<ull, ull> valores;

ull f(ull n){
    if(auto resultado = valores.find(n); resultado != valores.end()) 
        return (*resultado).second;
    
    valores[n/2] = f(n/2);
    valores[n/3] = f(n/3);
    return valores[n/2] + valores[n/3];
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ull n, aux, aux2;

	cin >> n;
    valores[0] = 1;

	cout << f(n) << "\n";
	return 0;
}