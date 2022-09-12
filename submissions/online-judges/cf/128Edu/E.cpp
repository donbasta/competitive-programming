#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    vector<vector<int>> ss(2, vector<int>(n + 1));
    vector<vector<ll>> dpl(n + 2, vector<ll>(3)), dpr(n + 2, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        ss[0][i + 1] = (s[0][i] == '*' ? 1 : 0);
        ss[1][i + 1] = (s[1][i] == '*' ? 1 : 0);
    }
    vector<bool> exl(n + 2), exr(n + 2), can(n + 2), canr(n + 2);
    for (int i = 1; i <= n; i++) {
        if (ss[1][i] == 1) {
            dpl[i][0] = 1 + min(dpl[i - 1][1], dpl[i - 1][0]) + (exl[i - 1] ? 1 : 0);
            exl[i] = true;
        } else if (ss[0][i] == 1) {
            ll a = dpl[i - 1][1] + (exl[i - 1] ? 2 : 0);
            ll b = dpl[i - 1][0] + (exl[i - 1] ? 1 : 0);
            dpl[i][0] = min(a, b);
            exl[i] = true;
        } else {
            ll a = dpl[i - 1][1] + (exl[i - 1] ? 2 : 0);
            ll b = dpl[i - 1][0] + (exl[i - 1] ? 1 : 0);
            dpl[i][0] = min(a, b);
            exl[i] = exl[i - 1];
        }

        if (ss[0][i] == 1) {
            dpl[i][1] = 1 + min(dpl[i - 1][0], dpl[i - 1][1]) + (exl[i - 1] ? 1 : 0);
            exl[i] = true;
        } else if (ss[1][i] == 1) {
            ll a = dpl[i - 1][0] + (exl[i - 1] ? 2 : 0);
            ll b = dpl[i - 1][1] + (exl[i - 1] ? 1 : 0);
            dpl[i][1] = min(a, b);
            exl[i] = true;
        } else {
            ll a = dpl[i - 1][0] + (exl[i - 1] ? 2 : 0);
            ll b = dpl[i - 1][1] + (exl[i - 1] ? 1 : 0);
            dpl[i][1] = min(a, b);
            exl[i] = exl[i - 1];
        }

        if (ss[0][i] == 1 && ss[1][i] == 1) {
            dpl[i][2] = (can[i - 1] ? dpl[i - 1][2] + 2 : 0);
            can[i] = true;
        } else if (ss[0][i] == 1) {
            ll tmp = 1e18;
            if (can[i - 1]) {
                tmp = min(tmp, dpl[i - 1][2] + 2);
                can[i] = true;
            }
            if (exl[i - 1]) {
                tmp = min({tmp, dpl[i - 1][0] + 2, dpl[i - 1][1] + 1});
                can[i] = true;
            }
            dpl[i][2] = tmp;
        } else if (ss[1][i] == 1) {
            ll tmp = 1e18;
            if (can[i - 1]) {
                tmp = min(tmp, dpl[i - 1][2] + 2);
                can[i] = true;
            }
            if (exl[i - 1]) {
                tmp = min({tmp, dpl[i - 1][1] + 2, dpl[i - 1][0] + 1});
                can[i] = true;
            }
            dpl[i][2] = tmp;
        } else {
            if (can[i - 1]) {
                dpl[i][2] = dpl[i - 1][2] + 2;
                can[i] = true;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (ss[1][i] == 1) {
            dpr[i][0] = 1 + min(dpr[i + 1][1], dpr[i + 1][0]) + (exr[i + 1] ? 1 : 0);
            exr[i] = true;
        } else if (ss[0][i] == 1) {
            ll a = dpr[i + 1][1] + (exl[i + 1] ? 2 : 0);
            ll b = dpr[i + 1][0] + (exl[i + 1] ? 1 : 0);
            dpr[i][0] = min(a, b);
            exr[i] = true;
        } else {
            ll a = dpr[i + 1][1] + (exl[i + 1] ? 2 : 0);
            ll b = dpr[i + 1][0] + (exl[i + 1] ? 1 : 0);
            dpr[i][0] = min(a, b);
            exr[i] = exr[i + 1];
        }

        if (ss[0][i] == 1) {
            dpr[i][1] = 1 + min(dpr[i + 1][0], dpr[i + 1][1]) + (exr[i + 1] ? 1 : 0);
            exr[i] = true;
        } else if (ss[1][i] == 1) {
            ll a = dpr[i + 1][0] + (exr[i + 1] ? 2 : 0);
            ll b = dpr[i + 1][1] + (exr[i + 1] ? 1 : 0);
            dpr[i][1] = min(a, b);
            exr[i] = true;
        } else {
            ll a = dpr[i + 1][0] + (exr[i + 1] ? 2 : 0);
            ll b = dpr[i + 1][1] + (exr[i + 1] ? 1 : 0);
            dpr[i][1] = min(a, b);
            exr[i] = exr[i + 1];
        }

        if (ss[0][i] == 1 && ss[1][i] == 1) {
            dpr[i][2] = (canr[i + 1] ? dpr[i + 1][2] + 2 : 0);
            canr[i] = true;
        } else if (ss[0][i] == 1) {
            ll tmp = 1e18;
            if (canr[i + 1]) {
                tmp = min(tmp, dpr[i + 1][2] + 2);
                canr[i] = true;
            }
            if (exl[i - 1]) {
                tmp = min({tmp, dpr[i + 1][0] + 2, dpr[i + 1][1] + 1});
                canr[i] = true;
            }
            dpr[i][2] = tmp;
        } else if (ss[1][i] == 1) {
            ll tmp = 1e18;
            if (can[i - 1]) {
                tmp = min(tmp, dpr[i + 1][2] + 2);
                canr[i] = true;
            }
            if (exl[i - 1]) {
                tmp = min({tmp, dpr[i + 1][1] + 2, dpr[i + 1][0] + 1});
                canr[i] = true;
            }
            dpr[i][2] = tmp;
        } else {
            if (can[i - 1]) {
                dpr[i][2] = dpr[i + 1][2] + 2;
                canr[i] = true;
            }
        }
    }
    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        if ((!exl[i]) && (!exr[i])) {
            continue;
        } else if (!exl[i - 1]) {
            ans = min({ans, dpr[i][0], dpr[i][1]});
        } else if (!exr[i + 1]) {
            ans = min({ans, dpl[i][0], dpl[i][1]});
        } else {
            assert((i > 1) && (i < n));
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ll tmp = dpl[i - 1][j] + dpr[i + 1][k] + 2 + (j != k);
                    if ((j == k) && (ss[1 - j][i] == 1)) {
                        tmp++;
                    }
                    ans = min(ans, tmp);
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
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}