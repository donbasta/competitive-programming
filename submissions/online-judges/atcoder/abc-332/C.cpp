#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int m, n;
    cin >> n >> m;
    string s;
    cin >> s;
    int c1 = 0, c2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ans = max(ans, max(c2, c1 - m));
            c1 = c2 = 0;
        } else {
            c1++;
            c2 += (s[i] == '2');
        }
    }
    ans = max(ans, max(c2, c1 - m));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}