#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int mex(const set<int>& se) {
    int j = 0;
    for (auto i : se) {
        if (j != i) {
            return j;
        }
        j++;
    }
    return j;
}

void solve() {
    int p, k;
    cin >> p >> k;
    vector<vector<int>> ve(p), gr(p);
    for (int i = 0; i < p; i++) {
        int n;
        cin >> n;
        ve[i].resize(n);
        gr[i].resize(n + 1);
        for (int j = 0; j < n; j++) {
            cin >> ve[i][j];
        }
        gr[i][0] = 0;
        gr[i][1] = (ve[i][0] == 1 ? 1 : 0);
        for (int j = 2; j <= n; j++) {
            set<int> tmp;
            for (int take = 0; take <= min(k, j - 1); take++) {
                int ambil = take + ve[i][j - take - 1];
                if (ambil > j) {
                    continue;
                }
                tmp.emplace(gr[i][j - ambil]);
            }
            gr[i][j] = mex(tmp);
        }
    }
    int cek = 0;
    for (int i = 0; i < p; i++) {
        cek ^= gr[i].back();
    }
    cout << (cek ? "Alice can win." : "Bob will win.") << '\n';
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