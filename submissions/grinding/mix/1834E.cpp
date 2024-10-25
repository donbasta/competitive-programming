#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;

ll LCM(ll x, ll y) {
    if ((x / __gcd(x, y)) > (INF / y)) return INF;
    return (x / __gcd(x, y)) * y;
}

struct SparseTable {
    const int K = 20;
    vector<vector<ll>> table;
    vector<int> lg2;
    int n;
    ll MAX;
    SparseTable(const vector<ll>& ar, ll MAX) : n(ar.size()), MAX(MAX), lg2(ar.size() + 1) {
        table.resize(K + 1);
        for (auto& v : table) v.resize(n + 5);
        for (int i = 0; i < n; i++) {
            table[0][i] = ar[i];
        }
        for (int i = 1; i <= K; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                ll ki = table[i - 1][j];
                ll ka = table[i - 1][j + (1 << (i - 1))];
                if (ki == INF || ka == INF) {
                    table[i][j] = INF;
                    continue;
                }
                ll lcm = LCM(ki, ka);
                if (lcm > MAX)
                    table[i][j] = INF;
                else
                    table[i][j] = lcm;
            }
        }
        lg2[1] = 0;
        for (int i = 2; i <= n; i++) {
            lg2[i] = lg2[i / 2] + 1;
        }
    }
    ll get(int l, int r) {
        int i = lg2[r - l + 1];
        ll ki = table[i][l], ka = table[i][r - (1 << i) + 1];
        if (ki == INF || ka == INF) return INF;
        ll lcm = LCM(ki, ka);
        if (lcm > MAX) return INF;
        return lcm;
    }
};

void el_psy_congroo() {
    ll n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll M = n * (n + 1) / 2 + 1;
    SparseTable st(ar, M);
    set<ll> can;
    for (int i = 0; i < n; i++) {
        ll cur = ar[i];
        can.insert(cur);
        int l = i + 1;
        while (l < n) {
            int lo = l, hi = n - 1, piv = -1;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                ll cek = st.get(l, mid);
                if (cek == INF || (cur % cek != 0)) {
                    hi = mid - 1;
                } else {
                    piv = mid;
                    lo = mid + 1;
                }
            }
            if (piv == -1) {
                cur = LCM(cur, ar[l]);
                can.insert(cur);
                l++;
                if (cur > M) break;
            } else {
                l = piv + 1;
                if (l == n) break;
                cur = LCM(cur, ar[l]);
                can.insert(cur);
                if (cur > M) break;
            }
        }
    }
    ll tmp = 1;
    for (auto c : can) {
        if (c == tmp)
            tmp++;
        else
            break;
    }
    cout << tmp << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}