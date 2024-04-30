#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if(a == 0 && b == 0 && c != 0)
        cout << -c << "\n";
    else if((b * c) > (b + c))
        cout << a - (b * c) << "\n";
    else
        cout << a - (b + c) << "\n";
    return 0;
}
