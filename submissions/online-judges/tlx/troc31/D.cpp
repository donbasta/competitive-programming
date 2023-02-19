#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ve;
    vector<int> pp(n), ww(n);
    for (int i = 0; i < n; i++) cin >> pp[i];
    for (int i = 0; i < n; i++) cin >> ww[i];
    for (int i = 0; i < n; i++) {
        ve.emplace_back(pp[i], ww[i]);
    }
    sort(ve.begin(), ve.end());
    reverse(ve.begin(), ve.end());

    ll ans = 0;
    priority_queue<int> pq;
    int cur = ve[0].first;
    pq.emplace(ve[0].second);
    for (int i = 1; i < n; i++) {
        if (ve[i].first == cur)
            pq.emplace(ve[i].second);
        else {
            int sel = cur - ve[i].first;
            while ((sel > 0) && (!pq.empty())) {
                ans += pq.top();
                pq.pop();
                sel--;
            }
            cur = ve[i].first;
            pq.emplace(ve[i].second);
        }
    }
    while ((cur > 0) && (!pq.empty())) {
        ans += pq.top();
        pq.pop();
        cur--;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}