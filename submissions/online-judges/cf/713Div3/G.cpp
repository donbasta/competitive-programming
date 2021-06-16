#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e7;

ll d[N + 5];
int ans[N + 5];

void sieve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            d[j] += i;
        }
    }
    for (int i = N; i >= 1; i--) {
        if (d[i] > N) continue;
        ans[d[i]] = i;
    }
}

int c;

void solve() {
    cin >> c;
    cout << ans[c] << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(ans, -1, sizeof(ans));
    sieve();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}