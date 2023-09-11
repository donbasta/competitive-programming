#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> ve(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ve[i][j];
        }
    }
    vector<pair<int, pair<ll, int>>> rank;
    for (int i = 0; i < n; i++) {
        sort(ve[i].begin(), ve[i].end());
        int cur = 0;
        ll pen = 0;
        int score = 0;
        for (int j = 0; j < m; j++) {
            if (cur + (ve[i][j]) <= h) {
                score++;
                cur += ve[i][j];
                pen += cur;
            } else {
                break;
            }
        }
        rank.emplace_back(-score, make_pair(pen, i));
    }
    sort(rank.begin(), rank.end());
    for (int i = 0; i < n; i++) {
        if (rank[i].second.second == 0) {
            cout << i + 1 << '\n';
            return;
        }
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