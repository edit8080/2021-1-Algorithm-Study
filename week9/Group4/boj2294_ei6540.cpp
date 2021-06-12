#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int dp[10000 + 1];
int coin[100 + 1];

void solve() {

	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
	}

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];

}

int main() {
	FASTIO
	solve();
}
