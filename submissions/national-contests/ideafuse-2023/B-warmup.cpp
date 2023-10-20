#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int mn = 2e9;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        mn = min(mn, x);
    }
    sum -= mn;
    cout << sum << '\n';
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