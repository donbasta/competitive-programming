#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll to_ll (string s) {
    ll ret = 0, pw = 1;
    reverse(s.begin(), s.end());
    for (auto c : s) {
        if (c == '1') ret += pw;
        pw <<= 1;
    }
    return ret;
}

string to_str (ll l, int sz) {
    string ret;
    while (l) {
        if (l & 1) ret.push_back('1');
        else ret.push_back('0');
        l >>= 1;
    }
    while ((int)ret.size() < sz) ret.push_back('0');
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve() {
    int n, m;
    ll k;
    cin >> n >> m;
    k = (1LL << m) - n;
    vector<ll> a(n);
    map<ll, bool> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = to_ll (s);
        mp[a[i]] = 1;
    }
    sort(a.begin(), a.end());
    ll mid = 1LL << (m - 1);
    for (ll i = mid - 55; i <= mid + 55; i++) {
        if (i < 0 || i >= (1LL << m)) continue;
        if (mp.count(i)) continue;
        int t = lower_bound(a.begin(), a.end(), i) - a.begin();
        if (i - t == (k - 1) / 2) {
            cout << to_str (i, m) << '\n';
            return;
        }
    }
    assert (false);
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