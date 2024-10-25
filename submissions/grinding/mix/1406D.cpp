#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

ll ceil(ll a, ll b) {
    if (a >= 0) return (a + b - 1) / b;
    return a / b;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), dif(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll cur = 0, ba = ar.back();
    for (int i = 0; i < n - 1; i++) {
        dif[i] = ar[i] - ar[i + 1];
        if (dif[i] > 0) cur += dif[i];
    }
    cout << ceil(ba + cur, 2) << '\n';
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        if (l > 0) {
            if (dif[l - 1] > 0) cur -= dif[l - 1];
            dif[l - 1] -= x;
            if (dif[l - 1] > 0) cur += dif[l - 1];
        }
        if (r < n - 1) {
            if (dif[r] > 0) cur -= dif[r];
            dif[r] += x;
            if (dif[r] > 0) cur += dif[r];
        }
        if (r == n - 1) ba += x;
        cout << ceil(ba + cur, 2) << '\n';
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