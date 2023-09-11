#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        int md = ar[i] % k;
        if (md == 0) md = k;
        mp[md].push_back(i);
    }
    vector<int> ans;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        for (auto e : it->second) {
            ans.push_back(e);
        }
    }
    for (auto e : ans) {
        cout << (e + 1) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}