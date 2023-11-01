#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MX = 1e6;
const ld pi = acos(-1);

void el_psy_congroo() {
    ld a;
    cin >> a;
    a = abs(a);
    a = a * pi / 180.0;
    ld cs = cos(a);
    vector<ld> cheb;
    cheb.push_back(1);
    cheb.push_back(cs);
    ld mn = abs(cs);
    ld mn_idx = 1;
    for (int i = 2; i <= MX; i++) {
        ld tmp = cheb[i - 1] * 2 * cs - cheb[i - 2];
        cheb.push_back(tmp);
        if (abs(tmp) < mn) {
            mn = abs(tmp);
            mn_idx = i;
        }
    }
    cerr << fixed << setprecision(16) << mn << ' ' << cheb[17] << '\n';
    // for (auto e : cheb) {
    //     cerr << e << ' ';
    // }
    // cerr << '\n';
    cout << mn_idx << '\n';
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