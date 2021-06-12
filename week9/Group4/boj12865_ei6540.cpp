#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int dp[101][100000 + 1];
int item[100 + 1][100 + 1];

void solve() {

	int n, k;
	cin >> n >> k;
	
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i][0] >> item[i][1];
    }

    for (int i = 1; i <= n; i++)
    {
        int weight = item[i][0], val = item[i][1];
        for (int j = 0; j <= k; j++)
        {
            if (j < item[i][0]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + val);
        }
    }

    cout << dp[n][k];

}

int main() {
	FASTIO
	solve();
}
