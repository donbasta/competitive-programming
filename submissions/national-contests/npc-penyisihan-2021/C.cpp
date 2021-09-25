#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

map<string, ll> mp;
int T;

void solve() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        string s;
        ll k;
        cin >> s >> k;
        set<string> se;
        for (int i = 1; i < 5; i++) {
            if (s[i] == '0') continue;
            for (int j = i + 1; j < 5; j++) {
                string t = s.substr(i, j - i + 1);
                se.insert(t);
            }
        }
        for (auto ss : se) {
            mp[ss] += k;
        }
    }
    ll mx = -1;
    string cur = "";
    for (auto p : mp) {
        if (mx < p.second) {
            mx = p.second;
            cur = p.first;
        } else if (mx == p.second) {
            if (stoi(cur) < stoi(p.first)) {
                cur = p.first;
            }
        }
    }
    cout << 'V' << cur << '\n';
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