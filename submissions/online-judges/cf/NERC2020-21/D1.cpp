#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, d;
vector<int> ve[10];
vector<pair<int, int>> pos[10];

void brute_force(const vector<int>& idx) {
    vector<pair<int, int>> all;
    all.emplace_back(1, 1);
    for (auto i : idx) {
        int cur_size = (int) all.size();
        for (int j = 0; j < (int) pos[i].size(); i++) {
            for (int k = 0; k < cur_size; k++) {
                all.emplace_back(all[k].first * pos[i][j].first % 10, all[k].second * pos[i][j].second);
            }
        }
    }
    for (auto e : all) {
        if (e.first == d && e.second < cur_min) {
            ans = 
        }
    }
}

void solve() {
    cin >> n >> d;

    for (int i = 1; i <= n; i++) {
        int ar;
        cin >> ar;
        if (ar % 5 == 0) ada5 = true;
        if (ar % 2 == 0) ada2 = true;
        vec.push_back(ar);
        ve[ar % 10].emplace_back(ar);
    }
    for (int i = 0; i < 10; i++) {
        sort(ve[i].begin(), ve[i].end());
    }
    if (d == 0) {
        if (!(ada2 && ada5)) {
            cout << -1 << '\n';
        } else {
            cout << n << '\n';
            for (auto e : vec) {
                cout << e << ' ';
            }
            cout << '\n';
        }
        return;
    }
    assert(d);
    vector<vector<int>> ld = {
        {}, {},
        {-1, 6, 2, 4, 8},
        {-1, 1, 3, 9, 7},
        {-1, 6, 4},
        {-1, 5},
        {-1, 6},
        {-1, 1, 7, 9, 3},
        {-1, 6, 8, 4, 2},
        {-1, 1, 9}
    };
    vector<int> cyc = {
        -1, -1, 4, 4, 2, 1, 1, 4, 4, 2
    };
    for (int i = 2; i <= 9; i++) {
        // pos[i].emplace_back(-1, 1);
        int len = (int) ve[i].size();
        if (len == 0) {
            continue;
        }
        int cur = 1;
        int tmp = len % cyc[i];
        for (int j = 0; j < min(cyc[i], len); j++) {
            pos[i].emplace_back(ld[i][tmp], cur);
            tmp = (tmp + cyc[i] - 1) % cyc[i];
            cur *= ve[i][j];
        }
    }
    brute_force();

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