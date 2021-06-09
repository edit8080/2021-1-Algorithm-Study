#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int cnt[1001];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


void solve() {

	cnt[0] = 1;
	cnt[1] = 1;
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cnt[i] = cnt[i - 1]+2*cnt[i - 2];
		cnt[i] %= 10007;
	}
	cout << cnt[N];

}


int main() {
	
	init();
	solve();
	
}
