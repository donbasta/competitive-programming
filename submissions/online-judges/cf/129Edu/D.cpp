#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;
int n;
map<ll, int> mp;

ll dfs(string s, ll x) {
    if (mp.find(x) != mp.end()) {
        return mp[x];
    }
    if (s.length() >= n) {
        return 0;
    }

    vector<bool> dig(10);
    int mx = -1;
    for (auto c : s) {
        dig[c - '0'] = true;
        mx = max(mx, c - '0');
    }
    if (mx == 1) {
        return INF;
    }
    ll ans = INF;
    for (int i = 2; i < 10; i++) {
        if (dig[i]) {
            ll nx = x * i;
            ans = min(ans, 1 + dfs(to_string(nx), nx));
        }
    }
    return mp[x] = ans;
}

void solve() {
    ll x;
    cin >> n >> x;
    string s = to_string(x);
    ll ans = dfs(s, x);
    cout << (ans == INF ? -1 : ans) << '\n';
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