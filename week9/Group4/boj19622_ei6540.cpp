#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

long long dp[100000 + 1][2];
vector<pair<int, pair<long long, long long>>> meet;

void solve() {

	int N;
	cin >> N;
	meet.resize(N);
	
	for (int i = 0; i < N; i++) {
		// 사람, 시작시간, 끝시간
		cin >> meet[i].second.first >> meet[i].second.second >> meet[i].first;
	}
	
	dp[0][1] = meet[0].first;
	dp[1][1] = meet[1].first; 
	dp[1][0] = meet[0].first;

	for (int i = 2; i < N ; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + meet[i].first;
	}

	cout << max(dp[N-1][0], dp[N-1][1]);

}

int main() {
	FASTIO
	solve();
}
