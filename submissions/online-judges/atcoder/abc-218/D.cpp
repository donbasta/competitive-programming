#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<pair<int, int>> ve;
    set<pair<int, int>> se;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ve.emplace_back(x, y);
        se.insert(make_pair(x, y));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ve[i].first == ve[j].first) continue;
            if (ve[i].second == ve[j].second) continue;
            bool a = se.count(make_pair(ve[i].first, ve[j].second));
            bool b = se.count(make_pair(ve[j].first, ve[i].second));
            if (a && b) {
                ans++;
            }
        }
    }
    ans /= 2;
    cout << ans << '\n';
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