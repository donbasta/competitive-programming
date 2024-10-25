#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 3e5;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int n) : n(n) {
        tree.resize(n + 1);
    }
    void upd(int x, ll val) {
        while (x <= n) {
            tree[x] += val;
            x += x & -x;
        }
    }
    ll get(int x) {
        ll ret = 0;
        while (x) {
            ret += tree[x];
            x -= x & -x;
        }
        return ret;
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void el_psy_congroo() {
    ll ret = 0;

    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    BIT cnt(M), sum(M);
    vector<bool> ada(M + 1);
    cnt.upd(ar[0], 1);
    sum.upd(ar[0], ar[0]);

    ll cur_sum = ar[0];
    ada[ar[0]] = true;
    cout << ret << ' ';
    for (int i = 1; i < n; i++) {
        ll ka = cur_sum;
        for (int d = 0;; d++) {
            int le = max(1, d * ar[i]);
            int ri = min(M, (d + 1) * ar[i] - 1);
            ka -= 1ll * ar[i] * d * cnt.get(le, ri);
            if (ri >= M) break;
        }

        int bat = sqrt(ar[i]);  // floor(sqrt(ar[i]))
        ll ki = 0;
        for (int j = 0; j <= bat + 1; j++) {
            int le = ((ar[i] + 1 + j) / (j + 1));
            int ri = (j > 0 ? (ar[i] / j) : M);
            ki += cnt.get(le, ri) * ar[i] - sum.get(le, ri) * j;
        }
        for (int j = 2; j <= bat; j++) {
            if (!ada[j]) continue;
            if ((ar[i] / j) <= bat + 1) break;
            ki += (ar[i] % j);
        }

        // cerr << ki << ' ' << ka << '\n';

        sum.upd(ar[i], ar[i]);
        cnt.upd(ar[i], 1);

        ada[ar[i]] = true;
        cur_sum += ar[i];
        ret = (ret + ka + ki);
        cout << ret << ' ';
    }
    cout << '\n';
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