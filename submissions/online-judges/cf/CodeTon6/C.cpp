#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    vector<bool> ada(k + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ada[ar[i]] = true;
    }
    vector<int> pref(n), suf(n);
    pref[0] = ar[0];
    for (int i = 1; i < n; i++) {
        pref[i] = max(pref[i - 1], ar[i]);
    }
    suf[n - 1] = ar[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], ar[i]);
    }
    reverse(suf.begin(), suf.end());
    for (int i = 1; i <= k; i++) {
        int u = lower_bound(pref.begin(), pref.end(), i) - pref.begin();
        int v = lower_bound(suf.begin(), suf.end(), i) - suf.begin();
        v = n - 1 - v;
        bool ok = (u < n);
        ok &= ((ar[u] == i) || (ar[u] > i && ada[i]));
        ok &= ((ar[v] == i) || (ar[v] > i && ada[i]));
        if (!ok) {
            cout << 0 << ' ';
        } else {
            cout << ((v - u + 1) * 2) << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}