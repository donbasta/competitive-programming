#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), mx(n), mn(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    mx[0] = ar[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], ar[i]);
    }
    mn[n - 1] = ar[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mn[i] = min(mn[i + 1], ar[i]);
    }
    vector<int> ve;
    for (int i = 0; i < n; i++) {
        ll le = (i ? (mx[i - 1]) : -INF);
        ll ri = ((i < n - 1) ? mn[i + 1] : INF);
        if ((le < ar[i]) && (ar[i] < ri)) {
            ve.push_back(ar[i]);
        }
    }
    cout << ve.size() << ' ';
    for (int i = 0; i < min(100, (int)ve.size()); i++) {
        cout << ve[i] << ' ';
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