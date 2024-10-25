#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e18;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i) {
            d[j]++;
        }
    }
    vector<int> nx(n, -1);
    for (int i = 1; i < n; i++) {
        nx[i] = (i + d[i]) % n;
    }
    const int B = 21;
    vector<vector<int>> up(n, vector<int>(B, -1));
    vector<vector<ll>> tot(n, vector<ll>(B, -1));
    for (int i = 0; i < n; i++) up[i][0] = nx[i];
    for (int i = 0; i < n; i++) tot[i][0] = i;
    for (int i = 1; i < B; i++) {
        for (int j = 0; j < n; j++) {
            if (up[j][i - 1] == -1) {
                tot[j][i] = tot[j][i - 1];
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
                tot[j][i] = tot[j][i - 1] + tot[up[j][i - 1]][i - 1];
            }
        }
    }
    vector<int> vis(n, -1);
    vector<int> mx(n);
    int col = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] >= 0) continue;
        int cur = i;
        vis[cur] = col;
        vector<int> tmp = {i};
        cur = nx[cur];
        while (cur != -1 && vis[cur] == -1) {
            tmp.push_back(cur);
            vis[cur] = col;
            cur = nx[cur];
        }
        if (cur == -1 || vis[cur] != col) {
            int lmao = (cur >= 0 ? mx[cur] + 1 : 1);
            for (int i = tmp.size() - 1; i >= 0; i--) {
                mx[tmp[i]] = lmao++;
            }
        } else {
            int st = -1;
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] == cur) {
                    st = i;
                    break;
                }
            }
            assert(st != -1);
            int cyc_len = (int)tmp.size() - st;
            for (int i = tmp.size() - 1; i >= 0; i--) {
                if (i >= st) {
                    mx[tmp[i]] = cyc_len;
                } else {
                    mx[tmp[i]] = cyc_len + st - i;
                }
            }
        }
        col++;
    }
    ll ans = INF;
    int st = -1;
    // for (int i = 0; i < n; i++) {
    //     cerr << i << ' ' << mx[i] << ' ' << nx[i] << ' ' << vis[i] << '\n';
    // }
    for (int i = 0; i < n; i++) {
        if (mx[i] < k) continue;
        int tmp = k;
        int cur = i;
        ll lol = 0;
        for (int j = B - 1; j >= 0; j--) {
            if (tmp >= (1 << j)) {
                lol += tot[cur][j];
                cur = up[cur][j];
                tmp -= (1 << j);
            }
        }
        if (lol < ans) {
            ans = lol;
            st = i;
        }
    }
    if (st == -1) {
        cout << -1 << '\n';
    } else {
        int cur = st;
        for (int i = 0; i < k; i++) {
            cout << cur << ' ';
            cur = nx[cur];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}