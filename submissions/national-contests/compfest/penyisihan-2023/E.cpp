#include <bits/stdc++.h>
using namespace std;

const int maxq = 303;
int n, q;
long long a[maxq];
bool active[3][maxq];
long long mn[3][maxq][maxq];
vector<int> queries[maxq];
long long dp[2][maxq][maxq][3];  // nomor query, terakhir kali pake salah satu lift, terakhir kali pake salah satu lift, lift terakhir
long long ans;

void self_min(long long &x, long long y) {
    if (x == -1)
        x = y;
    else
        x = min(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    a[0] = 1e9 + 3;
    for (int i = 1; i <= q; i++) cin >> a[i];
    queries[0] = {1, 1, 1};
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            queries[i] = {type, -1, -1};
            cin >> queries[i][1] >> queries[i][2];
        } else {
            queries[i] = {type, -1};
            cin >> queries[i][1];
        }
    }

    // cout << '\n';
    // for (int i=0; i<=q; i++) {
    // 	for (int u : queries[i]) cout << u << ' ';
    // 	cout << '\n';
    // }

    // cout << "yey\n";

    for (int i = 0; i < 3; i++) {
        active[i][0] = true;
        for (int j = 1; j <= q; j++) {
            active[i][j] = active[i][j - 1];
            if (queries[j][0] == 2 && queries[j][1] == i + 1) active[i][j] ^= 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= q; j++) {
            mn[i][j][j] = (active[i][j] ? a[j] : 1e18 + 3);
            for (int k = j + 1; k <= q; k++) {
                mn[i][j][k] = min(mn[i][j][k - 1], (active[i][k] ? a[k] : (long long)1e18 + 3));
            }
        }
    }

    memset(dp[0], -1, sizeof dp[0]);
    for (int i = 0; i < 3; i++) dp[0][0][0][i] = 0;
    long long lst = 1;
    for (int i = 1; i <= q; i++) {
        memset(dp[i & 1], -1, sizeof dp[i & 1]);
        if (queries[i][0] == 1) {
            int s = queries[i][1], t = queries[i][2];
            for (int l1 = 0; l1 < i; l1++) {
                for (int l2 = 0; l2 < i; l2++) {
                    for (int l3 = 0; l3 < 3; l3++) {
                        if (dp[!(i & 1)][l1][l2][l3] == -1) continue;
                        long long f1 = queries[l1][2], f2 = queries[l2][2], f3 = lst;
                        if (l3 == 0) {  // l1 itu last query lift 1, l2 itu last query lift 2, f1 itu lantai lift 1, f2 itu lantai lift 2
                            // coba pake lift 0
                            if (active[0][i])
                                self_min(dp[i & 1][l1][l2][0], dp[!(i & 1)][l1][l2][l3] + mn[0][i - 1][i] * abs(f3 - s) + a[i] * abs(s - t));
                            // coba pake lift 1
                            if (active[1][i])
                                self_min(dp[i & 1][i - 1][l1][1], dp[!(i & 1)][l1][l2][l3] + mn[1][l1][i] * abs(f1 - s) + a[i] * abs(s - t));
                            // coba pake lift 2
                            if (active[2][i])
                                self_min(dp[i & 1][i - 1][l2][2], dp[!(i & 1)][l1][l2][l3] + mn[2][l2][i] * abs(f2 - s) + a[i] * abs(s - t));
                        } else if (l3 == 1) {  // l1 itu last query lift 0, l2 itu last query lift 2, f1 itu lantai lift 0, f2 itu lantai lift 2
                            // coba pake lift 0
                            if (active[0][i])
                                self_min(dp[i & 1][i - 1][l2][0], dp[!(i & 1)][l1][l2][l3] + mn[0][l1][i] * abs(f1 - s) + a[i] * abs(s - t));
                            // coba pake lift 1
                            if (active[1][i])
                                self_min(dp[i & 1][l1][l2][1], dp[!(i & 1)][l1][l2][l3] + mn[1][i - 1][i] * abs(f3 - s) + a[i] * abs(s - t));
                            // coba pake lift 2
                            if (active[2][i])
                                self_min(dp[i & 1][l1][i - 1][2], dp[!(i & 1)][l1][l2][l3] + mn[2][l2][i] * abs(f2 - s) + a[i] * abs(s - t));
                        } else {  // l1 itu last query lift 0, l2 itu last query lift 1, f1 itu lantai lift 0, f2 itu lantai lift 1
                            // coba pake lift 0
                            if (active[0][i])
                                self_min(dp[i & 1][l2][i - 1][0], dp[!(i & 1)][l1][l2][l3] + mn[0][l1][i] * abs(f1 - s) + a[i] * abs(s - t));
                            // coba pake lift 1
                            if (active[1][i])
                                self_min(dp[i & 1][l1][i - 1][1], dp[!(i & 1)][l1][l2][l3] + mn[1][l2][i] * abs(f2 - s) + a[i] * abs(s - t));
                            // coba pake lift 2
                            if (active[2][i])
                                self_min(dp[i & 1][l1][l2][2], dp[!(i & 1)][l1][l2][l3] + mn[2][i - 1][i] * abs(f3 - s) + a[i] * abs(s - t));
                        }
                    }
                }
            }
            lst = t;

            // long long tmp = 1e18+3;
            // for (int j=0; j<=q; j++) {
            // 	for (int k=0; k<=q; k++) {
            // 		for (int l=0; l<3; l++) {
            // 			if (dp[i&1][j][k][l] != -1) tmp = min(tmp, dp[i&1][j][k][l]);
            // 		}
            // 	}
            // }
            // cout << i << ' ' << tmp << '\n';
        } else {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l < 3; l++) {
                        dp[i & 1][j][k][l] = dp[!(i & 1)][j][k][l];
                    }
                }
            }
        }
    }

    ans = 1e18 + 3;
    for (int i = 0; i <= q; i++) {
        for (int j = 0; j <= q; j++) {
            for (int k = 0; k < 3; k++) {
                if (dp[q & 1][i][j][k] != -1) ans = min(ans, dp[q & 1][i][j][k]);
            }
        }
    }

    // cout << dp[q&1][5][7] << '\n';
    // cout << dp[q&1][7][5] << '\n';

    cout << ans << '\n';

    return 0;
}