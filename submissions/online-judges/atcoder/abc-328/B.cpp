#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    int ans = 0;

    auto rep = [&](string s) -> bool {
        string c = s;
        sort(c.begin(), c.end());
        return c[0] == c.back();
    };

    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        for (int j = 1; j <= d; j++) {
            string si = to_string(i);
            string sj = to_string(j);
            if (rep(si) && rep(sj) && si[0] == sj[0]) {
                ans++;
            }
        }
    }
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