#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
const int INF = 2e9;

void solve() {
    cin >> n >> m;
    vector<vector<int>> ar(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ar[i][j];
        }
    }
    ll ganti = 0;
    for (int col = 1; col <= m; col++) {
        map<int, int> cnt;
        int tmp = n;
        for (int row = 1; row <= n; row++) {
            if ((ar[row][col] % m) != (col % m)) {
                continue;
            }
            int cek = (ar[row][col] - 1) / m;
            if (cek < 0 || cek >= n) {
                continue;
            }
            int cyc = row - 1 - cek;
            if (cyc < 0) cyc += n;
            cnt[cyc]++;
        }
        for (auto el : cnt) {
            tmp = min(tmp, el.first + n - el.second);
        }
        ganti += tmp;
    } 
    cout << ganti << '\n';
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