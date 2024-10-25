#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1, -1) {}
    void upd(int idx, int val) {
        idx++;
        while (idx <= n) {
            bit[idx] = max(bit[idx], val), idx += idx & -idx;
        }
    }
    int get(int idx) {
        idx++;
        int ret = -1;
        while (idx) {
            ret = max(ret, bit[idx]), idx -= idx & -idx;
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<vector<int>> pos(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        pos[i].push_back(0);
    }
    BIT ft(n + 2);
    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pos[ar[i]].push_back(i);
    }
    for (int i = 1; i <= n + 1; i++) {
        pos[i].push_back(n + 1);
    }
    for (int i = 1; i <= n + 1; i++) {
        bool ok = false;
        for (int j = 0; j < (int)pos[i].size() - 1; j++) {
            if (pos[i][j + 1] == pos[i][j] + 1) continue;
            int L = pos[i][j], R = pos[i][j + 1];
            int cek = ft.get(L);
            // cerr << i << ' ' << L << ' ' << R << ' ' << cek << '\n';
            if (cek < R) {
                ok = true;
            }
        }
        if (!ok) {
            cout << i << '\n';
            return;
        }
        for (int j = 0; j < (int)pos[i].size() - 1; j++) {
            ft.upd(pos[i][j], pos[i][j + 1]);
        }
    }
    cout << (n + 2) << '\n';
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