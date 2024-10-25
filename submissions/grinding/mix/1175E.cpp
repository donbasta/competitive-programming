#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;
const int M = 5e5;
const int B = 20;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> itv;
    vector<int> ri(M, -1), pre(M, -1);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ri[l] = max(ri[l], r);
    }
    pre[0] = ri[0];
    for (int i = 1; i < M; i++) pre[i] = max(pre[i - 1], ri[i]);
    vector<vector<int>> nx(M + 1, vector<int>(B));
    nx[M][0] = M;
    for (int i = M - 1; i >= 0; i--) {
        int j = pre[i];
        if (j == -1) j = i;
        nx[i][0] = j;
    }
    for (int i = 1; i < B; i++) {
        for (int j = 0; j <= M; j++) {
            nx[j][i] = nx[nx[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        int cur = x;
        for (int i = B - 1; i >= 0; i--) {
            if (nx[cur][i] >= y) continue;
            cur = nx[cur][i];
            cnt += (1 << i);
        }
        if (nx[cur][0] < y) {
            cout << -1 << '\n';
        } else {
            cout << (cnt + 1) << '\n';
        }
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