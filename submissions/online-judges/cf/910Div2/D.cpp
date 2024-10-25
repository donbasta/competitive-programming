#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(A[i] - B[i]);
    }
    vector<pair<int, int>> itv, itv2;
    for (int i = 0; i < n; i++) {
        int l = A[i], r = B[i];
        if (l > r) swap(l, r);
        itv.emplace_back(l, r);
    }
    itv2 = itv;
    sort(itv.begin(), itv.end());
    sort(itv2.begin(), itv2.end(), [&](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second < b.second;
    });
    pair<int, int> le = itv2[0], ri = itv.back();
    if (le.second < ri.first) {
        ans += 2ll * (ri.first - le.second);
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