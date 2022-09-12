#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 1), L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    // L[i] <= a[i] <= R[i]
    for (int i = 1; i <= n; i++) {
        R[i] = (b[i] ? (i / b[i]) : INF);
        L[i] = (i / (b[i] + 1)) + 1;
    }
    vector<pair<pair<int, int>, int>> itv;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        itv.emplace_back(make_pair(L[i], R[i]), i);
    }
    sort(itv.begin(), itv.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) -> bool {
        if (a.first.second == b.first.second) {
            return a.first.first > b.first.first;
        }
        return a.first.second < b.first.second;
    });
    set<int> se;
    for (int i = 1; i <= n; i++) {
        se.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        int idx = itv[i - 1].second;
        int l = itv[i - 1].first.first, r = itv[i - 1].first.second;
        int ch = *se.lower_bound(l);
        assert(ch <= r);
        ans[idx] = ch;
        se.erase(ch);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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