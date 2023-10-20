#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int x;
    cin >> x;
    if (x & 1) {
        cout << -1 << '\n';
        return;
    }
    int q = x / 2;
    for (int i = 0; i < 29; i++) {
        bool a = ((q >> i) & 1);
        bool b = ((q >> (i + 1)) & 1);
        if (a && b) {
            cout << -1 << '\n';
            return;
        }
    }
    int a = q * 3, b = q;
    cout << a << ' ' << b << '\n';
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