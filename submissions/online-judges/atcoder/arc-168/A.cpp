#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = 0;
    ll ans = 0;
    for (auto c : s) {
        if (c == '>') {
            len++;
        } else {
            ans += 1ll * len * (len + 1) / 2;
            len = 0;
        }
    }
    ans += 1ll * len * (len + 1) / 2;
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