#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int d;

void solve() {
    cin >> d;
    while (d--) {
        int n, k;
        cin >> n >> k;
        assert(k == 1);
        if (n == 1) {
            cout << -1 << ' ' << -1;
        } else if (n & 1) {
            cout << (n - 1) / 2 << ' ' << (n + 3) / 2;
        } else {
            if ((n & (n - 1)) == 0) {
                cout << -1 << ' ' << -1;
            } else {
                int cn = n;
                while (cn % 2 == 0) cn /= 2;
                assert(cn > 1);
                int y = -1;
                for (ll i = 3; 1LL * i * i <= 1LL * cn; i += 2) {
                    if (cn % i == 0) {
                        y = i;
                    }
                }
                if (y == -1) y = cn;
                int x = 2 * n / y;
                if (x < y) swap(x, y);
                cout << (x - y + 1) / 2 << ' ' << (x + y + 1) / 2;
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}