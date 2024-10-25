#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<ll> r(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    sort(r.begin(), r.end());
    for (int i = 0; i < n; i++) {
        pref[i] = r[i] + (i ? pref[i - 1] : 0);
    }
    while (q--) {
        ll x;
        cin >> x;
        int idx = upper_bound(pref.begin(), pref.end(), x) - pref.begin();
        cout << idx << '\n';
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