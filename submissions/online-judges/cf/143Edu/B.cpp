#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    int bruhL = 0, bruhR = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l == k) bruhL++;
        if (r == k) bruhR++;
    }
    cout << (((bruhL >= 1) && (bruhR >= 1)) ? "YES" : "NO") << '\n';
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