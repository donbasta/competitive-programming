#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

void solve() {
    cin >> n >> m;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ve.emplace_back(min(u, m), 0);
        ve.emplace_back(min(v, m), 1);
    }
    sort (ve.begin(), ve.end());
    int cnt = 0, cant = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i > 0 && cnt > 0) {
            cant += ve[i].first - ve[i - 1].first;
        }
        if (ve[i].second == 1) cnt--;
        else cnt++;
    }
    cout << m - 1 - cant << '\n';
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