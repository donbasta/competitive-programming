#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int ans;
    if (b >= 0) {
        ans = (a + b) * n;
    } else {
        int part = 1;
        for (int i = 1; i < n; i++) {
            part += (s[i] != s[i - 1]);
        }
        ans = a * n + b * ((part + 2) / 2);
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