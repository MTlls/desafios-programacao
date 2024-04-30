#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

bool custom_comparator(tuple<ll, int, ll> const& a, tuple<ll, int, ll> const& b) {
	if(get<0>(a) == get<0>(b)) {
		if(get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);

		return get<1>(a) < get<1>(b);
	}
	return get<0>(a) > get<0>(b);
}

int main() {
	int n, k, formato_int;
	ll t, u, b = 0;
	string formato;

	priority_queue<tuple<ll, int, ll>, vector<tuple<ll, int, ll>>, decltype(&custom_comparator)> arquivos(custom_comparator);

	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		cin >> u >> formato >> t;

		if(formato.compare("TMP") == 0)
			formato_int = 3;
		else if(formato.compare("OGG") == 0)
			formato_int = 2;
		else if(formato.compare("CPP") == 0)
			formato_int = 1;

		arquivos.push(make_tuple(u, formato_int, t));
	}

	// priority_queue<tuple<ll, int, ll>, vector<tuple<ll, int, ll>>, decltype(&custom_comparator)> temp_arquivos(custom_comparator);

	// while(!arquivos.empty()) {
	// 	auto arquivo = arquivos.top();
	// 	arquivos.pop();

	// 	int u = get<0>(arquivo);
	// 	int formato_int = get<1>(arquivo);
	// 	int t = get<2>(arquivo);

	// 	string formato;
	// 	if(formato_int == 1)
	// 		formato = "CPP";
	// 	else if(formato_int == 2)
	// 		formato = "OGG";
	// 	else if(formato_int == 3)
	// 		formato = "TMP";

	// 	cout << u << " " << formato << " " << t << endl;

	// 	temp_arquivos.push(arquivo);
	// }

	// arquivos = temp_arquivos;  // Restore the original queue

	for(int i = 0; i < k; i++) {
		b += get<2>(arquivos.top());
		arquivos.pop();
	}
	cout << b << "\n";

	return 0;
}
