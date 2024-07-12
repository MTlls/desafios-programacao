	#include <bits/stdc++.h>

	using namespace std;

	using ull = unsigned long long;

	int main() {
		cin.tie(0);
		ios_base::sync_with_stdio(false);

		ull n;
		int ai, bi, ci;

		cin >> n;
		vector<int> tabela_ferias(n * 3);
		vector<ull> dp(n * 3, 0);

		cin >> dp[0] >> dp[1] >> dp[2];

		tabela_ferias[0] = dp[0];
		tabela_ferias[1] = dp[1];
		tabela_ferias[2] = dp[2];

		for(int i = 1; i < n; i++) {
			cin >> ai >> bi >> ci;

			tabela_ferias[(3 * i)] = ai;
			tabela_ferias[(1) + (3 * i)] = bi;
			tabela_ferias[(2) + (3 * i)] = ci;
		}

		// soh para imprimir
		// for(int i = 0; i < n; i++) {
		// 	cout << tabela_ferias[(3 * i)] << " " << tabela_ferias[(1) + (3 * i)] << " " << tabela_ferias[(2) + (3 * i)] << "\n";
		// }

		// cout << "\n";
		// for (int i = 0; i < n; i++) {
		// 	cout << dp[(3 * i)] << " " << dp[(1) + (3 * i)] << " " << dp[(2) + (3 * i)] << "\n";
		// }

		for(int i = 1; i < n; i++) {
			dp[i * 3] = max(dp[1 + ((i - 1) * 3)], dp[2 + ((i - 1) * 3)]) + tabela_ferias[i * 3];
			dp[1 + (i * 3)] = max(dp[((i - 1) * 3)], dp[2 + ((i - 1) * 3)]) + tabela_ferias[1 + (i * 3)];
			dp[2 + (i * 3)] = max(dp[((i - 1) * 3)], dp[1 + ((i - 1) * 3)]) + tabela_ferias[2 + (i * 3)];
		}
		
		cout << max(dp[((n - 1) * 3)], max(dp[1 + ((n - 1) * 3)], dp[2 + ((n - 1) * 3)])) << "\n";
		return 0;
	}