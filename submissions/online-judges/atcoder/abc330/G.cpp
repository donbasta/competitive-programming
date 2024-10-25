#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> A(n), avail(n);
    vector<bool> ada(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] != -1) {
            --A[i];
            ada[A[i]] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        avail[i] = (!ada[i]) + ((i > 0) ? avail[i - 1] : 0);
    }
    ll ksg = avail[n - 1];
    ll cnt_inv = 0;

    vector<ll> fc(n + 1);
    fc[0] = 1;
    for (int i = 1; i <= n; i++) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }

    vector<vector<ll>> cnt(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll isi;
            if (A[i] == -1 && A[j] == -1) {
                isi = (ksg * (ksg - 1) / 2) % MOD;
                isi = (isi * fc[ksg - 2]) % MOD;
            } else if (A[i] == -1) {
                isi = avail[n - 1] - avail[A[j]];
                isi = (isi * fc[ksg - 1]) % MOD;
            } else if (A[j] == -1) {
                isi = (A[i] > 0 ? avail[A[i] - 1] : 0);
                isi = (isi * fc[ksg - 1]) % MOD;
            } else {
                isi = (A[i] > A[j]);
                isi = (isi * fc[ksg]) % MOD;
            }
            cnt_inv += isi;
            cnt[i][j] = isi;
        }
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