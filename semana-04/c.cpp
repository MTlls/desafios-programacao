#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    unsigned long long qntd, total = 0;
    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> qntd;
        if(qntd > 10)
            total += qntd - 10;
    
    }
    
    cout << total << "\n";
    return 0;
}