#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int B = 30;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> ve(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ve[i][j];
        }
    }
    vector<int> ret(n);
    for (int i = 0; i < B; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                tmp += ((ve[j][k] >> i) & 1);
            }
            if (tmp == n - 1) {
                ret[j] ^= (1 << i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((ret[i] | ret[j]) != ve[i][j]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
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