#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> ar(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += (ar[i][j] == -1);
        }
        if (tmp == n) {
            cout << -1 << '\n';
            return;
        }
        tmp = 0;
        for (int j = 0; j < n; j++) {
            tmp += (ar[j][i] == -1);
        }
        if (tmp == n) {
            cout << -1 << '\n';
            return;
        }
    }
    if (n == 2) {
        int x = ar[0][0] + ar[1][1];
        int y = ar[1][0] + ar[0][1];
        vector<vector<int>> check(2, vector<int>(2));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) check[i][j] = (ar[i][j] != -1);
        int sum1 = -1, sum2 = -1;
        if (check[0][0] + check[1][1] == 2) sum1 = x;
        if (check[0][1] + check[1][0] == 2) sum2 = y;
        int ret;
        assert((sum1 != -1) || (sum2 != -1));
        if ((sum1 != -1) && (sum2 != -1)) {
            if (sum1 != sum2)
                ret = 0;
            else
                ret = 1;
        } else {
            if (sum1 != -1) {
                if (check[0][1])
                    ret = ar[0][1] <= sum1;
                else if (check[1][0])
                    ret = ar[1][0] <= sum1;
                else
                    ret = sum1 + 1;
            } else if (sum2 != -1) {
                if (check[0][0])
                    ret = ar[0][0] <= sum2;
                else if (check[1][1])
                    ret = ar[1][1] <= sum2;
                else
                    ret = sum2 + 1;
            }
        }
        cout << ret << '\n';
        return;
    }
    cout << -1 << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}