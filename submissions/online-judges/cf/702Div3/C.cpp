#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll x;
const ll MX = 1e4;
set<ll> se;

void init() {
    for (ll i = 1; i <= MX; i++) {
        se.insert(i * i * i);
    }
}

void solve() {
    cin >> x;
    for (ll i = 1; i * i * i < x; i++) {
        ll j = x - i * i * i;
        if (se.count(j)) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}