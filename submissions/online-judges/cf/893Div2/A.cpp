#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll anna = a + (c + 1) / 2;
    ll katie = b + (c - (c + 1) / 2);
    if (anna > katie) {
        cout << "First";
    } else {
        cout << "Second";
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