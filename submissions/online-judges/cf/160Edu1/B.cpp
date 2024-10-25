#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    string s;
    cin >> s;
    int n = s.length();
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        c0 += s[i] == '0';
        c1 += s[i] == '1';
    }
    int ans = n;
    int need0 = 0, need1 = 0;
    for (int i = 0; i < n; i++) {
        need1 += s[i] == '0';
        need0 += s[i] == '1';
        if (need1 > c1 || need0 > c0) break;
        ans = min(ans, c1 - need1 + c0 - need0);
    }
    cout << ans << '\n';
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