#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

class BusTravel {
   public:
    int optimize(int N, int S, int M, int A) {
        int cost[N][N][N];
        int B = N - S;
        if (B == 0) return 0;
        for (int i = 1; i <= B; i++) {
            for (int y = 0; y < N; y++) {
                for (int z = 0; z < N; z++) {
                    if (y == z) continue;
                    cost[i][y][z] = (1ll * i * (y + 4) * (y + z + A) % M) + 1;
                }
            }
        }

        int ret = INF;
        vector<int> sites;
        for (int i = 0; i < (1 << N); i++) {
            if (__builtin_popcount(i) == S) {
                sites.push_back(i);
            }
        }
        for (auto s : sites) {
            vector<int> dp(1 << B, INF), ss, pos;
            for (int i = 0; i < N; i++) {
                if ((s >> i) & 1)
                    ss.push_back(i);
                else
                    pos.push_back(i);
            }
            dp[0] = 0;
            for (int i = 1; i < (1 << B); i++) {
                int cur = __builtin_popcount(i);
                for (int j = 0; j < B; j++) {
                    if (!((i >> j) & 1)) continue;
                    int best = INF;
                    for (auto c : ss) {
                        best = min(best, cost[B + 1 - cur][pos[j]][c]);
                    }
                    for (int k = 0; k < B; k++) {
                        if (k == j) continue;
                        if ((i >> k) & 1) best = min(best, cost[B + 1 - cur][pos[j]][pos[k]]);
                    }
                    dp[i] = min(dp[i], dp[i ^ (1 << j)] + best);
                }
            }
            ret = min(ret, dp[(1 << B) - 1]);
        }
        return ret;
    }
};

void el_psy_congroo() {
    int N, S, M, A;
    cin >> N >> S >> M >> A;
    BusTravel B;
    cout << B.optimize(N, S, M, A) << '\n';
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
