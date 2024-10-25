#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ld a, b;
    cin >> a >> b;
    ld am = (a + b) / 2;
    ld gm = sqrtl(a * b);
    ld hm = ld(2) / (ld(1) / a + ld(1) / b);
    cout << fixed << setprecision(15);
    cout << am << '\n';
    cout << gm << '\n';
    cout << hm << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}