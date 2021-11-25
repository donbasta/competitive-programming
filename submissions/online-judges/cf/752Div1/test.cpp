#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MX = 1e9;

ll lcm(ll a, ll b) {
    return a * (b / __gcd(a, b));
}

void solve() {
    vector<ll> lol;
    ll now = 2;
    int i = 3;
    while (now < MX) {
        lol.push_back(now);
        now = lcm(now, i++);
    }
    cerr << lol.size();
    for (auto e : lol) {
        cerr << e << '\n';
    }
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