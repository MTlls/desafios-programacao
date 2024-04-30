#include <bits/stdc++.h>
using namespace std;

int main() {
    string materia;
    int m, h;
    double h_total;

    while(cin >> materia) {
        cin >> h >> m;

        h_total = h + m/60.0;

        if(h_total > 10)
            cout << "Abel deve cancelar ";
        else
            cout << "Abel deve cursar ";
        
        cout << materia << "\n";
    }

    return 0;
}
