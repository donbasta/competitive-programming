#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

set<ll> se;

void proc(ll a, ll b) {
    ll d = __gcd(a, b);
    for (ll i = 1; i * i <= d; i++) {
        if (d % i == 0) se.insert(i);
        if ((i * i != d) && (d % i == 0)) {
            se.insert(d / i);
        }
    }
}

void solve() {
    ll l, w;
    cin >> w >> l;
    se.clear();
    se.insert(1);
    se.insert(2);
    proc(l - 1, w - 1);
    proc(l, w - 2);
    proc(l - 2, w);
    cout << se.size() << ' ';
    for (auto e : se) {
        cout << e << ' ';
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