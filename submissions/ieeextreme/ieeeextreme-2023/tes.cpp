#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

ll f(ll x, ll mod) {
    ll k = x % mod;
    return min(k, mod - k);
}

void el_psy_congroo() {
    ll a, b, c;
    cin >> a >> b >> c;
    pair<ll, ll> mn = make_pair(f(a * 1, b), 1);
    ll idx = 1;
    for (int i = 2; i <= c; i++) {
        pair<ll, ll> t = make_pair(f(a * i, b), i);
        if (t.first * mn.second < t.second * mn.first) {
            mn = t;
            idx = i;
        }
    }
    cout << idx << '\n';
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