#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int t = i ^ (i >> 1);
        for (int b = n - 1; b >= 0; b--) {
            if ((t >> b) & 1)
                cout << '1';
            else
                cout << '0';
        }
        cout << '\n';
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