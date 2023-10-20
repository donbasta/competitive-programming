#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    bool ok1 = ((n % a == 0) && (n % b != 0));
    bool ok2 = ((n % c == 0));
    cout << ((ok1 || ok2) ? "YES" : "NO") << '\n';
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