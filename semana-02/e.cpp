#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	int t;
	ll l, n, p, diff;
	double meio;

    map<double, ll> formigas;
	cin >> t;

	for(ll i = 0; i < t; i++) {
		cin >> l >> n;
		formigas.clear();

        meio = l / 2.0;
		cout << "meio " << meio << "\n";
        for(ll j = 0; j < n; j++) {
			cin >> p;
            
			// cout << "inserindo <"<<  abs(p - meio) << ","<< p << ">\n";
            diff = abs(p - meio);

            formigas.insert(make_pair(diff, p));
		}
        
		if((*formigas.begin()).second <= meio)
			cout << (*formigas.begin()).second << " ";
		else
			cout << l - (*formigas.begin()).second << " ";
		
		if(prev(formigas.end())->second < meio)
        	cout << l - prev(formigas.end())->second << "\n";   
		else
			cout << prev(formigas.end())->second<< "\n";
	}

	return 0;
}