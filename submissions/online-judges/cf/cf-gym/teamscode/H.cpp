#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int M = 1e6;

int occ[M + 5];
ll fc[M + 5];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int d;
        cin >> s >> d;
        occ[d]++;
    }
    fc[0] = 1;
    for (int i = 1; i <= M; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ll ans = 1;
    for (int i = 1; i <= M; i++) {
        ans = (ans * fc[occ[i]]) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}