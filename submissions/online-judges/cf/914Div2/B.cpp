#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n), pre(n), ret(n);
    vector<pair<ll, ll>> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ve[i] = make_pair(ar[i], i);
    }
    sort(ve.begin(), ve.end());
    pre[0] = ve[0].first;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + ve[i].first;
    }
    ret[ve[n - 1].second] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (pre[i] >= ve[i + 1].first) {
            ret[ve[i].second] = ret[ve[i + 1].second];
        } else {
            ret[ve[i].second] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
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