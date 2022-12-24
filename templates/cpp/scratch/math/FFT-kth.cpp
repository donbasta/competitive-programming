#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using cd = complex<ld>;
using vd = vector<ld>;
using vl = vector<ll>;

void fft(vector<cd>& a) {
    int n = (int)a.size(), L = 31 - __builtin_clz(n);
    static vector<cd> R(2, 1);
    static vector<cd> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        for (int i = k; i < 2 * k; i++) {
            rt[i] = R[i] = (i & 1) ? R[i / 2] * x : R[i / 2];
        }
    }
    vl rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    }
    for (int i = 0; i < n; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                cd z = rt[j + k] * a[i + j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}

vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};
    vd res((int)a.size() + (int)b.size() - 1);
    int L = 32 - __builtin_clz((int)res.size()), n = 1 << L;
    vector<cd> in(n), out(n);
    copy(a.begin(), a.end(), in.begin());
    for (int i = 0; i < (int)b.size(); i++) {
        in[i].imag(b[i]);
    }
    fft(in);
    for (cd& x : in) x *= x;
    for (int i = 0; i < n; i++) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    for (int i = 0; i < (int)res.size(); i++) {
        res[i] = imag(out[i]) / (4 * n);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cerr << fixed << setprecision(20);

    vd A, B;
    A = {1., 2.};
    B = {3., 4.};
    vd AB = conv(A, B);
    for (auto c : AB) {
        cerr << c << '\n';
    }

    return 0;
}