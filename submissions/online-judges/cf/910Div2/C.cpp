#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m, k;
    cin >> n >> m >> k;
    if ((n + m) % 2 != k % 2) {
        cout << "NO" << '\n';
        return;
    }
    if (k < (n + m - 2)) {
        cout << "NO" << '\n';
        return;
    }

    if ((n + m - 2) % 4 != k % 4) {
        if (k < (n + m)) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    vector<vector<char>> hori(n, vector<char>(m - 1, 'R'));
    vector<vector<char>> ver(m, vector<char>(n - 1, 'R'));
    for (int i = 0; i < m - 1; i++) {
        if (i & 1)
            hori[0][i] = 'R';
        else
            hori[0][i] = 'B';
    }
    for (int i = 0; i < n - 1; i++) {
        if (i & 1) {
            if (m & 1)
                ver[m - 1][i] = 'R';
            else
                ver[m - 1][i] = 'B';
        } else {
            if (m & 1)
                ver[m - 1][i] = 'B';
            else
                ver[m - 1][i] = 'R';
        }
    }
    if (ver[m - 1][n - 2] == 'R') {
        hori[n - 1][m - 2] = 'B';
        ver[m - 2][n - 2] = 'R';
        hori[n - 2][m - 2] = 'B';
    } else {
        hori[n - 1][m - 2] = 'R';
        ver[m - 2][n - 2] = 'B';
        hori[n - 2][m - 2] = 'R';
    }

    ver[0][0] = 'B';
    hori[1][0] = 'R';
    ver[1][0] = 'B';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << hori[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            cout << ver[j][i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}