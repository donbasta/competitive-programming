#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MX = 1e15;

void solve() {
    ll n;
    cin >> n;

    vector<ll> c;
    c.emplace_back(1);
    ll now = 5;
    while (now < MX) {
        // cerr << now << '\n';
        c.emplace_back(now);
        now = now * 5;
    }
    int N = c.size();
    set<ll> se;
    for (int i = 0; i < (1 << N); i++) {
        ll tmp = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1LL << j)) {
                tmp += c[j];
            }
        }
        se.emplace(tmp);
    }
    for (auto e : se) {
        if (se.count(e + n) || se.count(e - n)) {
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

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}