#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 998244353;

void el_psy_congroo() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<vector<int>>> segs(k, vector<vector<int>>(2));
    vector<int> L(m), R(m), X(m);
    for (int i = 0; i < m; i++) {
        cin >> L[i] >> R[i] >> X[i];
        for (int j = 0; j < k; j++) {
            segs[j][(X[i] >> j) & 1].push_back(vector<int>{L[i], R[i]});
        }
    }
    for (int i = 0; i < k; i++) {
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