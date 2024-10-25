#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 3e5;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin() + 1, ve.end());

    vector<vector<int>> id(N + 1);
    vector<int> to_id(N + 1);
    for (int i = 1; i <= n; i++) {
        to_id[ve[i]] = i;
    }
    // T[i] contains all indices r such that i divides ve[r]
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            if (to_id[j] == 0) continue;
            id[i].push_back(to_id[j]);
        }
    }
    vector<ll> T(N + 1);
    for (int i = 1; i <= N; i++) {
        int sz = id[i].size();
        if (sz < 2) continue;
        sort(id[i].begin(), id[i].end());
        int c = 1 - sz;
        for (int j = 0; j < sz; j++) {
            T[i] += 1ll * c * id[i][j];
            c += 2;
        }
        T[i] -= (1ll * sz * (sz - 1)) / 2;
    }
    for (int i = N; i >= 1; i--) {
        for (int j = i + i; j <= N; j += i) {
            T[i] -= T[j];
        }
    }
    cout << T[1] << '\n';
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