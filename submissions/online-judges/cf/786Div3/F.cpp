#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n) : n(_n) {
        bit.resize(n + 1);
    }
    void upd(int pos, int val) {
        while (pos <= n) {
            bit[pos] += val;
            pos += (pos & (-pos));
        }
    }
    int get(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += bit[pos];
            pos -= (pos & (-pos));
        }
        return ret;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> ce(n);
    BIT bit(n * m);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> ce[i];
        for (int j = 0; j < m; j++) {
            if (ce[i][j] == '*') {
                tot++;
                bit.upd(j * n + i + 1, 1);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int pos = y * n + x + 1;
        if (ce[x][y] == '*') {
            --tot;
            ce[x][y] = '.';
            bit.upd(pos, -1);
        } else {
            ++tot;
            ce[x][y] = '*';
            bit.upd(pos, 1);
        }
        int inside = bit.get(tot);
        cout << tot - inside << '\n';
    }

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