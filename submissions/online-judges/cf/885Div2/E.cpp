#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
int M;

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, M - 2);
}

void solve() {
    int x, q;
    cin >> x >> q >> M;
    unordered_map<int, int> pw;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i != 0) continue;
        while (x % i == 0) {
            x /= i;
            pw[i]++;
        }
    }
    if (x > 1) pw[x]++;
    ll ans = 1;
    for (auto e : pw) {
        ans = ans * (e.second + 1) % M;
    }
    set<int> lmao;
    while (q--) {
        int xi;
        cin >> xi;
        while (xi % 2 == 0) xi /= 2;
        for (int i = 3; i * i <= xi; i += 2) {
            if (xi % i != 0) continue;
            int awal = pw[i];
            while (xi % i == 0) {
                xi /= i;
                pw[i]++;
            }
            if ((awal + 1) % M == 0) {
                lmao.erase(i);
                ans = ans * (pw[i] + 1) % M;
            } else if ((pw[i] + 1) % M == 0) {
                ans = ans * inv(awal + 1) % M;
                lmao.insert(i);
            } else {
                ans = ans * inv(awal + 1) % M;
                ans = ans * (pw[i] + 1) % M;
            }
        }
        if (xi > 1) {
            int awal = pw[xi];
            pw[xi]++;
            if ((awal + 1) % M == 0) {
                lmao.erase(xi);
                ans = ans * (pw[xi] + 1) % M;
            } else if ((pw[xi] + 1) % M == 0) {
                ans = ans * inv(awal + 1) % M;
                lmao.insert(xi);
            } else {
                ans = ans * inv(awal + 1) % M;
                ans = ans * (pw[xi] + 1) % M;
            }
        }
        if (!lmao.empty()) {
            cout << 0 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}