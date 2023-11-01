#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> xx(n), yy(n);
    for (int i = 0; i < n; i++) {
        cin >> xx[i] >> yy[i];
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    ll ans = 0;
    if (n & 1) {
        cout << xx[n / 2] << ' ' << yy[n / 2] << '\n';
    } else {
        cout << xx[(n - 1) / 2] << ' ' << yy[(n - 1) / 2] << '\n';
    }
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