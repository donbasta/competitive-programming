#include <bits/stdc++.h>
using namespace std;

// taken from https://github.com/kth-competitive-programming/kactl/blob/main/content/various/FastInput.h
inline char gc() {  // like getchar()
    static char buf[1 << 16];
    static size_t bc, be;
    if (bc >= be) {
        buf[0] = 0, bc = 0;
        be = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[bc++];  // returns 0 on EOF
}

int readInt() {
    int a, c;
    while ((a = gc()) < 40)
        ;
    if (a == '-') return -readInt();
    while ((c = gc()) >= 48) a = a * 10 + c - 480;
    return a - 48;
}

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int N = 1e9 + 7;
const int D = 21;
const int M = 1e5;
const int MOD = 1e9 + 7;

int pw2[M + 5];

void init() {
    pw2[0] = 1;
    for (int i = 1; i <= 30; i++) {
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    }
}

void el_psy_congroo() {
    int n;
    // cin >> n;
    n = readInt();
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        // cin >> ve[i];
        ve[i] = readInt();
    }
    vector<int> base(D);
    vector<bool> penting(n);
    set<int> se;
    for (int i = 0; i < n; i++) {
        int msk = ve[i];
        for (int j = 0; j < D; j++) {
            if (!((msk >> j) & 1)) continue;
            if (!base[j]) {
                base[j] = msk;
                penting[i] = true;
                se.insert(i);
                break;
            }
            msk ^= base[j];
        }
    }
    se.insert(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int prv = i;
        int cnt = 0;
        for (auto e : se) {
            ans = (1ll * (e - prv) * pw2[cnt++] + ans) % MOD;
            prv = e;
        }
        if (penting[i]) {
            se.erase(i);
            int cur = i + 1;
            vector<int> base(D);
            while (cur < n) {
                // cek if ve[cur] representable or not
                if (penting[cur]) {
                    // tambahin ve[cur] ke base
                    int msk = ve[cur];
                    for (int j = 0; j < D; j++) {
                        if (!((msk >> j) & 1)) continue;
                        if (!base[j]) {
                            base[j] = msk;
                            break;
                        }
                        msk ^= base[j];
                    }
                    cur++;
                } else {
                    bool repr = true;
                    int msk = ve[cur];
                    for (int j = 0; j < D; j++) {
                        if (!((msk >> j) & 1)) continue;
                        if (!base[j]) {
                            repr = false;
                            break;
                        }
                        msk ^= base[j];
                    }
                    if (repr) {
                        cur++;
                    } else {
                        penting[cur] = true;
                        se.insert(cur);
                        break;
                    }
                }
            }
        }
    }

    // cout << ans << '\n';
    printf("%d\n", ans);
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    init();

    int TC = 1;
    // cin >> TC;
    TC = readInt();
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}
