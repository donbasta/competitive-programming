#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> val(n), par(n), dep(n), sum(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    ll mx = 0;
    for (int i = 1; i < n; i++) {
        cin >> par[i];
        --par[i];
        dep[i] = dep[par[i]] + 1;
        sum[dep[i]] += val[i];
        mx = max(mx, dep[i]);
    }
    bool all_zero = (val[0] == 0);
    ll last = val[0];
    for (int i = 1; i <= mx; i++) {
        all_zero &= (sum[i] == 0);
        if (sum[i] != 0) {
            last = sum[i];
        }
    }
    if (all_zero) {
        cout << 0 << '\n';
    } else if (last > 0) {
        cout << '+' << '\n';
    } else {
        cout << '-' << '\n';
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