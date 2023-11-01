#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void FST(vector<ll>& a, bool inv) {
    for (int n = a.size(), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i += 2 * step) {
            for (int j = i; j < i + step; j++) {
                ll &u = a[j], &v = a[j + step];
                tie(u, v) = make_pair(u + v, u - v);
            }
        }
    }
    if (inv)
        for (ll& x : a) x /= a.size();
}

vector<ll> conv(vector<ll> a, vector<ll> b) {
    FST(a, 0);
    FST(b, 0);
    for (int i = 0; i < a.size(); i++) {
        a[i] *= b[i];
    }
    FST(a, 1);
    return a;
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] ^ ar[i];
    }
    vector<ll> cnt(1 << 16);
    ll c0 = 0;
    for (int i = 0; i <= n; i++) {
        cnt[pref[i]]++;
    }
    for (auto e : cnt) {
        c0 += 1ll * e * (e - 1) / 2;
    }
    vector<ll> c = conv(cnt, cnt);
    vector<ll> res;
    ll mx = -1;
    ll val = -1;
    for (int i = 0; i < c.size(); i++) {
        ll tmp = (i == 0 ? c0 : (c[i] / 2));
        if (tmp > mx) {
            mx = tmp;
            val = i;
        }
    }
    cout << val << ' ' << mx << '\n';
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