#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cnt1 += (ar[i] == 1);
    }
    if ((cnt1 > 0) && (cnt1 < n)) {
        cout << -1 << '\n';
        return;
    } else if ((cnt1 > 0) && (cnt1 == n)) {
        cout << 0 << '\n';
        return;
    }

    set<pair<int, int>> se;
    for (int i = 0; i < n; i++) {
        se.insert(make_pair(ar[i], i));
    }

    vector<pair<int, int>> ans;
    while (se.begin()->first != se.rbegin()->first) {
        int mn = se.begin()->first;
        int id = se.begin()->second;
        for (int i = 0; i < n; i++) {
            if (i == id) continue;
            int cur = ar[i];
            while (ceil(cur, mn) > 1) {
                cur = ceil(cur, mn);
                ans.emplace_back(i, id);
            }
            se.erase(se.find(make_pair(ar[i], i)));
            ar[i] = cur;
            se.insert(make_pair(ar[i], i));
        }
    }

    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
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