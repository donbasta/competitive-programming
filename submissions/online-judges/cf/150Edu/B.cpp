#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int q;
    cin >> q;
    bool inc = true;
    int last = -1;
    int first = -1;
    while (q--) {
        int x;
        cin >> x;
        if (first == -1) {
            first = last = x;
            cout << '1';
        } else if (inc) {
            if (x >= last) {
                cout << '1';
                last = x;
            } else if (x > first) {
                cout << '0';
            } else {
                cout << '1';
                inc = false;
                last = x;
            }
        } else {
            if (x > first || x < last) {
                cout << '0';
            } else {
                cout << '1';
                last = x;
            }
        }
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
        solve();
    }

    return 0;
}