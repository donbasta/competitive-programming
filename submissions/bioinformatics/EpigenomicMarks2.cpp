#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll M1 = 1e9 + 123;
const ll M2 = 1e9 + 7;
const ll B = 5;

int n, l;

void solve() {
    cin >> n >> l;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<ll> pw1(n + 1), pw2(n + 1);
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw1[i] = (pw1[i - 1] * B) % M1;
        pw2[i] = (pw2[i - 1] * B) % M2;
    }
    int id = 0;
    map<pair<ll, ll>, int> mp;
    vector<pair<ll, ll>> lol(l);
    for (int i = 0; i < l; i++) {
        ll tmp1 = 0, tmp2 = 0;
        for (int j = 0; j < n; j++) {
            int dig = (s[j][i] - '0' + 1);
            tmp1 = (tmp1 + 1LL * dig * pw1[j + 1]) % M1;
            tmp2 = (tmp2 + 1LL * dig * pw2[j + 1]) % M2;
        }
        if (!mp.count(make_pair(tmp1, tmp2))) {
            mp[make_pair(tmp1, tmp2)] = ++id;
        }
        lol[i] = make_pair(tmp1, tmp2);
    }
    cout << id << '\n';
    for (int i = 0; i < l; i++) {
        cout << mp[lol[i]] << ' ';
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