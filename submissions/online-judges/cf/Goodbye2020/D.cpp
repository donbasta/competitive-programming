#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> w(n), deg(n);
    priority_queue<pair<int, int>> pq;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        cur += 1LL * w[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        deg[u]++, deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] > 1) {
            pq.emplace(w[i], deg[i] - 1);
        }
    }
    cout << cur << ' ';
    for (int i = 2; i < n; i++) {
        auto t = pq.top();
        pq.pop();
        cur += 1LL * t.first;
        cout << cur << ' ';
        if (t.second > 1) {
            pq.emplace(t.first, t.second - 1);
        }
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