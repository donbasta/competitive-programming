#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// using ll = __int128;
using ld = long double;

const int INF = 2e9;
const int B = 60;
const ll MX = 1e18;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        // int tmp;
        // cin >> tmp;
        // ar[i] = tmp;
        cin >> ar[i];
        // ar[i] = read();
    }

    vector<ll> need(B);
    vector<vector<ll>> cnt(B, vector<ll>(B));  // cnt[i][j] = count yg bit i off tp bit j nyala
    vector<vector<ll>> cnt2(B, vector<ll>(B));
    vector<bool> ok(B);
    for (int i = B - 1; i >= 0; i--) {
        int cnt_tmp = 0;
        for (int j = 0; j < n; j++) {
            int cur = ((ar[j] >> i) & 1);
            cnt_tmp += cur;
            if (cur == 0) {
                // indices[i].insert(j);
                need[i] += ((1ll << i) - (ar[j] & ((1ll << i) - 1)));
                if (need[i] > MX) {
                    break;
                }
            }
        }
        ok[i] = (cnt_tmp == n);
    }

    // for (int i = 2; i >= 0; i--) {
    //     cerr << "need initial " << i << ' ' << need[i] << '\n';
    // }

    for (int i = B - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            for (int kk = 0; kk < n; kk++) {
                int cx = ((ar[kk] >> i) & 1);
                int cy = ((ar[kk] >> j) & 1);
                cnt[i][j] += (cy && (!cx));
                if ((!cx) && (!cy)) {
                    cnt2[i][j] += (ar[kk] & ((1ll << j) - 1));
                    // cnt2[i][j] += ((1ll << j) - (ar[kk] & ((1ll << j) - 1)));
                }
            }
        }
    }

    vector<ll> k(q);
    for (int i = 0; i < q; i++) {
        // k[i] = read();
        cin >> k[i];
    }
    for (int i = 0; i < q; i++) {
        vector<ll> need_cur = need, last_op(B);
        vector<bool> ok_cur = ok;
        ll ret = 0;
        for (int j = B - 1; j >= 0; j--) {
            if (ok_cur[j]) {
                ret ^= (1ll << j);
                continue;
            }
            if (need_cur[j] > k[i]) continue;
            k[i] -= need_cur[j];
            ret ^= (1ll << j);
            // cerr << j << ' ' << need_cur[j] << ' ' << k[i] << '\n';
            for (int kk = j - 1; kk >= 0; kk--) {
                need_cur[kk] -= last_op[kk];
            }
            for (int kk = j - 1; kk >= 0; kk--) {
                ll curr = ((1ll << kk) * (cnt[j][kk]) + cnt2[j][kk]);
                need_cur[kk] += curr;
                last_op[kk] = curr;
                ok_cur[kk] = false;
                // cerr << "after op " << j << ' ' << kk << ' ' << need_cur[kk] << '\n';
            }
        }
        // print(ret);
        cout << ret << '\n';
        // cout << '\n';
        // cout << ret << '\n';
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