#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n - 1), b(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> pref(n - 1), suf(n - 1);
    {
        ll cur = 0;
        for (int i = 0; i < n - 1; i++) {
            while (cur < n && b[cur] <= a[i]) {
                cur++;
            }
            pref[i] = cur;
            if (cur < n) cur++;
        }
    }
    {
        ll cur = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (b[cur] > a[i]) {
                suf[i] = cur;
                cur--;
            } else {
                suf[i] = (i < n - 2 ? suf[i + 1] : n);
            }
        }
    }
    ll byk = 0;
    for (int i = 0; i < n - 1; i++) {
        if (pref[i] < n) byk++;
    }
    ll ans = byk * m;
    ll ptr = suf[0];
    if (ptr > 0) {
        ll cek = b[ptr - 1];
        ans += max(0ll, min({m, (cek - 1), a[0]}));
    }
    for (int i = 1; i < n - 1; i++) {
        ptr = suf[i];
        if (ptr > 0 && ptr - pref[i - 1] >= 2) {
            ll cek = b[ptr - 1];
            ans += max(0ll, min({m, cek - 1, a[i]}) - a[i - 1]);
        }
    }
    if (pref[n - 2] < n - 1) {
        ll cek = b[n - 1];
        ans += max(0ll, min(cek - 1, m) - a[n - 2]);
    }
    ll ret = n * m - ans;
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}