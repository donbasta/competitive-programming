#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 1e5 + 3;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }

    vector<int> f(1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> g(i + 1);
        g[0] = 1;
        for (int j = 1; j <= i; j++) {
            g[j] = (1ll * f[j - 1] * ar[i] + (j < i ? f[j] : 0)) % MOD;
        }
        f.swap(g);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << f[k] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}