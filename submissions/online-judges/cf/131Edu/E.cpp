#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
const int N = 5e3;
int D1[N + 5][N + 5], D2[N + 5][N + 5], D3[N + 5][N + 5], lcs[N + 5][N + 5];

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << '\n';
        return;
    }
    if (n <= m) {
        cout << -1 << '\n';
        return;
    }
    vector<char> ss(n + 1), tt(m + 1);
    for (int i = 0; i < n; i++) {
        ss[i + 1] = s[i];
    }
    for (int i = 0; i < m; i++) {
        tt[i + 1] = t[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            D1[i][j] = lcs[i][j] = 0;
            D2[i][j] = D3[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int k = lcs[i - 1][j];
            lcs[i][j] = k;
            if (k < j) {
                if (tt[k + 1] == ss[i]) {
                    lcs[i][j]++;
                }
            }
            int u = D1[i - 1][j - 1];
            if (ss[i] == tt[j]) {
                D1[i][j] = 1 + u;
            } else {
                D1[i][j] = 0;
            }
            if (lcs[i][j] == j) {
                D3[i][j] = 2 * i - j - D1[i][j];
            }
        }
    }
    if (lcs[n][m] < m) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i <= n; i++) {
        D2[i][0] = i;
        D3[i][0] = 2 * i;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            D1[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp = INF;
            if (D2[i - 1][j] != -1) tmp = min(tmp, D2[i - 1][j] + 1);
            if (s[i] == t[j]) {
                if (D2[i - 1][j - 1] != -1) tmp = min(tmp, D2[i - 1][j - 1] + 1);
            }
            if (D3[i][j] != -1) {
                tmp = min(tmp, D3[i][j] + 1);
            }
            if ((i == j) && (lcs[i][j] == j)) tmp = 0;
            if (tmp != INF) {
                D2[i][j] = tmp;
            }
            if (D3[i][j] != -1) {
                D1[i][j] = D3[i][j] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp = D1[i][j] == -1 ? INF : D1[i][j];
            if (D1[i - 1][j] != -1) tmp = min(tmp, D1[i - 1][j] + 1);
            if (s[i] == t[j]) {
                if (D2[i - 1][j - 1] != -1) tmp = min(tmp, D2[i - 1][j - 1] + 1);
            }
            if ((i == j) && (lcs[i][j] == j)) tmp = 0;
            if (tmp != INF) {
                D1[i][j] = tmp;
            }
        }
    }

    cout << D1[n][m] << '\n';
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