#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
string s;

int cn(int a, int j) {
    if (j == 0) return a / 3;
    return (a + 3 - j) / 3;
}

int cntz(int l, int r, int j) { return cn(r, j) - cn(l - 1, j); }

const int N = 2e5;

int cnt[N + 5][3][3];

void solve() {
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cnt[i][0][i % 3] = cnt[i - 1][0][i % 3] + (s[i - 1] == 'a');
        cnt[i][1][i % 3] = cnt[i - 1][1][i % 3] + (s[i - 1] == 'b');
        cnt[i][2][i % 3] = cnt[i - 1][2][i % 3] + (s[i - 1] == 'c');

        cnt[i][0][(i + 1) % 3] = cnt[i - 1][0][(i + 1) % 3];
        cnt[i][1][(i + 1) % 3] = cnt[i - 1][1][(i + 1) % 3];
        cnt[i][2][(i + 1) % 3] = cnt[i - 1][2][(i + 1) % 3];

        cnt[i][0][(i + 2) % 3] = cnt[i - 1][0][(i + 2) % 3];
        cnt[i][1][(i + 2) % 3] = cnt[i - 1][1][(i + 2) % 3];
        cnt[i][2][(i + 2) % 3] = cnt[i - 1][2][(i + 2) % 3];
    }

    while (m--) {
        int l, r;
        cin >> l >> r;

        vector<vector<int>> T(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                T[i][j] = cntz(l, r, j) - (cnt[r][i][j] - cnt[l - 1][i][j]);
            }
        }
        int ans = min({
            T[0][0] + T[1][1] + T[2][2], 
            T[0][0] + T[1][2] + T[2][1],
            T[0][1] + T[1][0] + T[2][2],
            T[0][1] + T[1][2] + T[2][0],
            T[0][2] + T[1][0] + T[2][1],
            T[0][2] + T[1][1] + T[2][0],
        });
        cout << ans << '\n';
    }
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