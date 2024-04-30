#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int iterador = 0, qntdImpares = 0;
    map<char, int> alfabeto;

    cin >> s;

    // for (size_t i = 0; i < 599; i++)
    // {
    //     cout << "A";
    // }
    // cout << "\n";
    // return 0;
    for (int i = 0; i < s.length(); i++) {
        alfabeto[s[i]]++;
    }

    if (s.length() % 2 == 0) {
        for (auto &elemento : alfabeto) {
            if (elemento.second % 2 == 1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
    } else {
        for (auto &elemento : alfabeto) {
            if (elemento.second % 2 == 1)
                qntdImpares++;
        }
        if (qntdImpares > 1 || qntdImpares == 0) {
            cout << "NO SOLUTION\n";
            return 0;
        }
    }

    string palindromo(s.length(), ' ');

    for (auto &elemento : alfabeto) {
        if (elemento.second % 2 == 1 && elemento.second == 1) {
            palindromo[s.length() / 2] = elemento.first;
        } else {
            do {
                palindromo[iterador] = elemento.first;
                palindromo[(s.length() - 1) - iterador] = elemento.first;
                iterador++;
                elemento.second -= 2;
            } while (elemento.second > 1);

            if (elemento.second == 1)
                palindromo[s.length() / 2] = elemento.first;
        }
    }

    cout << palindromo << "\n";
    return 0;
}
