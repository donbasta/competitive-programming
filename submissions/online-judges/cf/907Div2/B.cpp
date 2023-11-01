#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    vector<ll> ar(n), que(q);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> que[i];
    }

    vector<ll> A(31), B(31), P(31);
    for (int i = 1; i <= 30; i++) {
        ll a = 1, b = 0, pw = i;
        for (int j = 0; j < q; j++) {
            if (que[j] <= pw) {
                ll x = 1ll << (pw - que[j] + 1);
                a = a * x;
                b = b * x + 1;
                pw = que[j] - 1;
            }
        }
        A[i] = a, B[i] = b, P[i] = pw;
    }

    vector<ll> ret(n);
    for (int i = 0; i < n; i++) {
        int pw = 0;
        while (ar[i] % 2 == 0) {
            ar[i] /= 2, pw++;
        }
        if (pw == 0) {
            ret[i] = ar[i];
            continue;
        }
        ret[i] = (1ll << P[pw]);
        ret[i] *= (A[pw] * ar[i] + B[pw]);
    }
    for (auto e : ret) {
        cout << e << ' ';
    }
    cout << '\n';
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