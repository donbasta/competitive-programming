#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int D = 20;
const int MOD = 1e9 + 7;
const int M = 1e5;

int pw2[M + 5];

void init() {
    pw2[0] = 1;
    for (int i = 1; i <= M; i++) {
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    }
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> basis(D + 1);
        int sz = 0;
        for (int j = i; j < n; j++) {
            int mask = ve[j];
            for (int k = 0; k <= D; k++) {
                if (!((mask >> k) & 1)) continue;
                if (!basis[k]) {
                    basis[k] = mask;
                    ++sz;
                    break;
                }
                mask ^= basis[k];
            }
            ans = (ans + pw2[sz]) % MOD;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}