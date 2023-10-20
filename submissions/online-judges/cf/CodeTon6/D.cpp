#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int cur_min = c[n];
    vector<pair<int, int>> cand;
    cand.push_back(make_pair(c[n], n));
    for (int i = n - 1; i >= 1; i--) {
        if (c[i] >= cur_min) {
            continue;
        }
        cand.push_back(make_pair(c[i], i));
        cur_min = c[i];
    }
    reverse(cand.begin(), cand.end());
    int k;
    cin >> k;
    int bat = (k / cand[0].first);
    vector<int> cnt(n + 1);
    cnt[cand[0].second] = bat;
    int sisa = k - bat * (cand[0].first);
    for (int i = 1; i < (int)cand.size(); i++) {
        int add = c[cand[i].second] - c[cand[i - 1].second];
        int t = min((sisa / add), cnt[cand[i - 1].second]);
        cnt[cand[i - 1].second] -= t;
        cnt[cand[i].second] += t;
        sisa -= (t * add);
    }
    for (int i = n - 1; i >= 1; i--) {
        cnt[i] += cnt[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
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