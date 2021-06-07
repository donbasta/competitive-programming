#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n >> s;
    vector<int> D(n + 1), K(n + 1);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        D[i + 1] = D[i] + (s[i] == 'D');
        K[i + 1] = K[i] + (s[i] == 'K');
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int fpb = __gcd(D[i], K[i]);
        int dd = D[i] / fpb;
        int kk = K[i] / fpb;
        if (mp.find({dd, kk}) != mp.end()) {
            ans[i] = mp[{dd, kk}];
        } else {
            ans[i] = 0;
        }
        mp[{dd, kk}]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] + 1 << ' ';
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