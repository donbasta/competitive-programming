#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    ll sum = 0;
    vector<ll> w(n + 1);
    vector<ll> pre(n + 1);
    vector<vector<bool>> A(n + 1, vector<bool>(n + 1)), B(n + 1, vector<bool>(n + 1));
    vector<vector<bool>> PB1(n + 1, vector<bool>(n + 1, true)), PB2(n + 1, vector<bool>(n + 1, true));
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        pre[i] = (pre[i - 1] + w[i]);
        sum += w[i];
    }
    if (sum & 1) {
        for (int i = 1; i <= n; i++) {
            A[i][i] = ((w[i] & 1) ? true : false);
            B[i][i] = ((w[i] & 1) ? false : true);
            PB1[i][i] = B[i][i];
            PB2[i][i] = B[i][i];
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j + i - 1 <= n; j++) {
                ll sum = pre[j + i - 1] - pre[j - 1];
                if (sum & 1) {
                    A[j][j + i - 1] = true;
                    B[j][j + i - 1] = !(PB1[j][j + i - 2] && PB2[j + 1][j + i - 1]);
                } else {
                    A[j][j + i - 1] = !(PB1[j][j + i - 2] && PB2[j + 1][j + i - 1]);
                    B[j][j + i - 1] = true;
                }
                PB1[j][j + i - 1] = (PB1[j][j + i - 2] & B[j][j + i - 1]);
                PB2[j][j + i - 1] = (PB2[j + 1][j + i - 1] & B[j][j + i - 1]);
            }
        }

        int ans = 1;
        for (int i = 1; i <= n - 1; i++) {
            if (!A[1][i]) {
                ans++;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (!A[i][n]) {
                ans++;
            }
        }
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}