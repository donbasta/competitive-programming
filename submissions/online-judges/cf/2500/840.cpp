#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300;
const int MOD = 1e9 + 7;

int par[N + 5], sz[N + 5];
ll ar[N + 5], fc[N + 5];

inline bool isSquare(ll a) {
    ll s = sqrt(a);
    return (a == s * s);
}

void init () {
    for (int i = 1; i <= N; i++) {
        par[i] = i, sz[i] = 1;
    }
}

int fpar(int a) {
    return a == par[a] ? a : par[a] = fpar(par[a]);
}

void merge(int a, int b) {
    a = fpar(a), b = fpar(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

ll go(const vector<int>& ve) {
    fc[0] = 1;
    for (int i = 1; i <= N; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    ll ret = 1;
    for (auto e : ve) {
        ret = (ret * fc[e]) % MOD;
    }
    
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (isSquare(ar[i] * ar[j])) {
                merge(i, j);
            }
        }
    }
    vector<int> ve;
    for (int i = 1; i <= n; i++) {
        if (fpar(i) == i) {
            ve.emplace_back(sz[i]);
        }
    }
    ll ans = go(ve);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}