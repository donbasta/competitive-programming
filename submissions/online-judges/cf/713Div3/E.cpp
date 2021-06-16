#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n, l, r, s;

void solve() {
    cin >> n >> l >> r >> s;
    ll lo = (r - l + 1) * (r - l + 2) / 2;
    ll hi = (r - l + 1) * (l - r + 2 * n) / 2;
    if (s > hi || s < lo) {
        cout << -1 << '\n';
        return;
    }
    ll tmp = lo;
    vector<int> ar(n + 1);
    for (int i = l; i <= r; i++) {
        ar[i] = i - l + 1;
    }
    for (int i = r; i >= l; i--) {
        ll cap = n - (r - l + 1);
        ll need = s - tmp;
        if (need > cap) {
            ar[i] += cap;
            tmp += cap;
        } else {
            ar[i] += need;
            break;
        }
    }
    vector<bool> ada(n + 1, false);
    for (int i = l; i <= r; i++) {
        ada[ar[i]] = true;
    }
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= l && i <= r) continue;
        while (idx <= n && ada[idx]) idx++;
        ar[i] = idx;
        idx++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ar[i] << ' ';
    }
    cout << '\n';
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