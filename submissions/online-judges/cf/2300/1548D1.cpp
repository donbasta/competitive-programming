#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;

    vector<vector<int>> pt(2, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x >>= 1, y >>= 1;
        pt[x & 1][y & 1]++;
    }

    const auto calc = [&](int a, int b, int c) -> ll {
        int a1 = ((a >> 1) & 1), a2 = (a & 1);
        int b1 = ((b >> 1) & 1), b2 = (b & 1);
        int c1 = ((c >> 1) & 1), c2 = (c & 1);
        int A = pt[a1][a2];
        int B = pt[b1][b2];
        int C = pt[c1][c2];
        if (a == b && b == c) {
            return 1LL * A * (A - 1) * (A - 2) / 6;
        } else if (a == b) {
            return 1LL * A * (A - 1) * C / 2;
        } else if (b == c) {
            return 1LL * A * B * (B - 1) / 2;
        } else if (a == c) {
            return 1LL * A * (A - 1) * B / 2;
        } else {
            return 1LL * A * B * C;
        }
    };

    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            for (int k = j; k < 4; k++) {
                int tmp = ((i != j) + (j != k) + (k != i));
                if (tmp % 2 == 0) {
                    ans += calc(i, j, k);
                }
            }
        }
    }
    cout << ans << '\n';
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
