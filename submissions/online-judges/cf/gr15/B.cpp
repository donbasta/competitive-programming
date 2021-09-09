#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<vector<int>> r(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> r[i][j];
        }
    }
    int sup = 0;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            cnt += (r[sup][j] < r[i][j]);
        }
        if (cnt < 3) {
            sup = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == sup) continue;
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            cnt += (r[sup][j] < r[i][j]);
        }
        if (cnt < 3) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << sup + 1 << '\n';
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