#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> ar(n, vector<pair<int, int>>(m));
    vector<vector<int>> t(n), ve(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            ve[i][j] = tmp;
            ar[i][j] = make_pair(tmp, j);
        }
        sort(ar[i].begin(), ar[i].end());
        for (int j = 0; j < m; j++) {
            if ((ar[i][j].second != j) && (ar[i][j].first != ve[i][j])) {
                t[i].push_back(j);
            }
        }
    }
    set<int> se;
    for (int i = 0; i < n; i++) {
        if (t[i].size() >= 3) {
            cout << -1 << '\n';
            return;
        }
        if (t[i].size() == 2) {
            se.insert(t[i][0]);
            se.insert(t[i][1]);
        }
    }
    if (se.size() >= 3) {
        cout << -1 << '\n';
        return;
    }
    if (se.size() == 2) {
        int x = *se.begin();
        int y = *se.rbegin();
        bool ok = true;
        for (int i = 0; i < n; i++) {
            swap(ve[i][x], ve[i][y]);
            vector<int> tmp = ve[i];
            sort(tmp.begin(), tmp.end());
            if (ve[i] != tmp) {
                ok = false;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            return;
        }
        for (auto e : se) {
            cout << e + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    cout << 1 << ' ' << 1 << '\n';
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