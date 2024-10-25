#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    ll mn = *min_element(ar.begin(), ar.end());
    ll mx = *max_element(ar.begin(), ar.end());
    vector<ll> ret;
    while (mn < mx) {
        ll a = mn % 2, b = mx % 2;
        if (a == b) {
            ret.push_back(a);
            mn = (mn + a) / 2, mx = (mx + a) / 2;
        } else if (a == 0 && b == 1) {
            ret.push_back(0);
            mn /= 2, mx /= 2;
        } else if (a == 1 && b == 0) {
            ret.push_back(1);
            mn = (mn + 1) / 2, mx = (mx + 1) / 2;
        }
    }
    cout << ret.size() << '\n';
    if (ret.size() > 0 && ret.size() <= n) {
        for (auto e : ret) {
            cout << e << ' ';
        }
        cout << '\n';
    }
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