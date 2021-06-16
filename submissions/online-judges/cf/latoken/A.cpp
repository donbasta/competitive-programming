#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

void solve() {
    cin >> n >> m;
    vector<string> s(n);
    set<int> r, w;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            int par = (i + j) & 1;
            if (s[i][j] == 'R') {
                r.emplace(par);
            }
            if (s[i][j] == 'W') {
                w.emplace(par);
            }
        }
    }
    if (r.size() == 2 || w.size() == 2) {
        cout << "NO" << '\n';
        return;
    }
    if (r.size() == 1 && w.size() == 1 && *r.begin() == *w.begin()) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    int R = 1;
    if (!r.empty()) {
        R = *r.begin();
    } else if (!w.empty()) {
        R = 1 - *w.begin();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int par = (i + j) & 1;
            if (par == R) s[i][j] = 'R';
            else s[i][j] = 'W';
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
    return;
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