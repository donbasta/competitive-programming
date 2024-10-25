#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int ans;
        if (a < l) {
            ans = l;
        } else if (a > r) {
            ans = r;
        } else {
            ans = a;
        }
        cout << ans << ' ';
    }
    cout << '\n';
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