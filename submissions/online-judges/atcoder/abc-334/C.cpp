#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1, 2);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        cnt[x]--;
    }
    vector<int> rem;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            rem.push_back(i);
        }
    }
    int sz = rem.size();
    ll ans = 0;
    if (sz % 2 == 0) {
        for (int i = 1; i < sz; i += 2) {
            ans += rem[i] - rem[i - 1];
        }
        cout << ans << '\n';
        return;
    }
    vector<ll> prf(sz), suf(sz);
    for (int i = 1; i < sz; i += 2) {
        prf[i] = (i >= 2 ? prf[i - 2] : 0) + rem[i] - rem[i - 1];
    }
    for (int i = sz - 2; i >= 0; i -= 2) {
        suf[i] = (i + 2 < sz ? suf[i + 2] : 0) + rem[i + 1] - rem[i];
    }
    ans = 1e18;
    for (int i = 0; i < sz; i += 2) {
        ll ki = (i >= 1 ? prf[i - 1] : 0);
        ll ka = (i + 1 < sz ? suf[i + 1] : 0);
        ans = min(ans, ki + ka);
    }
    cout << ans << '\n';
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