#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    vector<int> ans(n);
    for (auto e : mp) {
        if (e.second.size() <= 1) {
            cout << -1 << '\n';
            return;
        }
        int sz = e.second.size();
        for (int i = 0; i < sz; i++) {
            ans[e.second[i]] = e.second[(i + 1) % sz];
        }
    }
    for (int i = 0; i < n; i++) {
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