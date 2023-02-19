#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    if (n <= 3) {
        cout << -1 << '\n';
        return;
    }
    int l = 0, r = n - 1;
    int curMin = 1, curMax = n;
    while (l <= r) {
        if (ar[l] == curMin) {
            l++, curMin++;
        } else if (ar[r] == curMin) {
            r--, curMin++;
        } else if (ar[l] == curMax) {
            l++, curMax--;
        } else if (ar[r] == curMax) {
            r--, curMax--;
        } else {
            cout << l + 1 << ' ' << r + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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