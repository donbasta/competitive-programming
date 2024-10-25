#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int k, g, m;
    cin >> k >> g >> m;
    int a = 0, b = 0;
    for (int i = 0; i < k; i++) {
        if (a == g)
            a = 0;
        else if (b == 0)
            b = m;
        else {
            if (g - a >= b) {
                a += b;
                b = 0;
            } else {
                b -= (g - a);
                a = g;
            }
        }
    }
    cout << a << ' ' << b << '\n';
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