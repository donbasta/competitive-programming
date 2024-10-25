#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), suf(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    suf[n - 1] = ar[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + ar[i];
    }
    ll ret = suf[0];
    for (int i = 1; i < n; i++) {
        if (suf[i] > 0) ret += suf[i];
    }
    cout << ret << '\n';
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