#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
int n;

void solve() {
    cin >> n;
    vector<ll> c(n);
    vector<vector<ll>> cnt(n, vector<ll>(n));
    vector<vector<ll>> mx(n, vector<ll>(n, -INF));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cnt[i][i] = c[i];
        mx[i][i] = cnt[i][i];
        for (int j = i + 1; j < n; j++) {
            int mul = (((j - i) & 1) ? -1 : 1);
            cnt[i][j] = cnt[i][j - 1] + 1LL * mul * c[j];
            mx[i][j] = max(mx[i][j - 1], cnt[i][j]);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            ans += min(c[i], c[i + 1]);
        }
        for (int j = i + 3; j < n; j += 2) {
            ll A = mx[i + 1][j - 1];              
            if (c[i] < A) {
                continue;
            }
            ll atas = min(c[i] - cnt[i + 1][j - 1], c[j]);
            ll bawah = max(A - cnt[i + 1][j - 1], 1LL);
            if (bawah > atas) {
                continue;
            }
            ll add = (atas - bawah + 1);
            ans += add;
        }
    }
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