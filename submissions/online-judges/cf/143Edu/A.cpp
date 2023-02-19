#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    reverse(t.begin(), t.end());
    s += t;
    int cnt = 0;
    for (int i = 1; i < m + n; i++) {
        if (s[i] == s[i - 1]) cnt++;
    }
    cout << (cnt <= 1 ? "YES" : "NO") << '\n';
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