#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, i_digit, carry = 0;
    string n1, n2, sum;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n1 >> n2;

        int digit = (n1.back() - '0') + (n2.back() - '0');

        if (digit % 2 == 0)
            cout << PARCEIROSn;
        else
            cout << NAO PARCEIROSn;

    }
    return 0;
}
