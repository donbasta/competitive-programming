#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ar(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
        }
    }
    int x = (n + 1) / 2;
    --x;
    int ans = INT_MIN;
    for (int i = 0; i < (1 << (x + 1)); i++) {
        int tmp = 0;
        vector<int> bit(x + 1);
        for (int j = 0; j <= x; j++) {
            bit[j] = (i >> j) & 1;
        }
        for (int j = 0; j <= x; j++) {
            tmp += (bit[j] ? (-1) : 1) * ar[j][x];
        }
        for (int j = x + 1; j < n; j++) {
            int ch = bit[j - x - 1] ^ bit[x];
            tmp += (ch ? (-1) : 1) * ar[j][x];
        }
        for (int j = 0; j < x; j++) {
            vector<int> mx(2);
            for (int b = 0; b < 2; b++) {
                for (int k = 0; k < x; k++) {
                    int lmao = INT_MIN;
                    for (int c = 0; c < 2; c++) {
                        int lol = 0;
                        int p = c, q = (c ^ b), r = (p ^ bit[k]), s = (q ^ bit[k] ^ bit[x]);
                        lol += (p ? (-1) : 1) * ar[k][j];
                        lol += (q ? (-1) : 1) * ar[k + x + 1][j];
                        lol += (r ? (-1) : 1) * ar[k][j + x + 1];
                        lol += (s ? (-1) : 1) * ar[k + x + 1][j + x + 1];
                        lmao = max(lmao, lol);
                    }
                    mx[b] += lmao;
                }
                mx[b] += (b ? (-1) : 1) * ar[x][j];
                mx[b] += ((b ^ bit[x]) ? (-1) : 1) * ar[x][j + x + 1];
            }
            tmp += max(mx[0], mx[1]);
        }
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}