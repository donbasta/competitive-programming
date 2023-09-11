#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    if (ar[0] == ar.back()) {
        assert(ar[0] == 0);
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    vector<ll> ret;
    ll cnt = 0;
    int cnt_zero = 0;
    vector<ll> pos, neg;
    for (auto e : ar) {
        if (e > 0)
            pos.push_back(e);
        else if (e < 0)
            neg.push_back(e);
        else
            cnt_zero++;
    }
    for (int i = 0; i < cnt_zero; i++) {
        ret.push_back(0);
    }
    int ip = 0, in = 0;
    for (int i = 0; i < n - cnt_zero; i++) {
        if (cnt > 0) {
            assert(in < neg.size());
            ret.push_back(neg[in]);
            cnt += neg[in];
            in++;
        } else if (cnt <= 0) {
            assert(ip < pos.size());
            ret.push_back(pos[ip]);
            cnt += pos[ip];
            ip++;
        }
    }
    assert(cnt == 0);
    for (auto e : ret) {
        cout << e << ' ';
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
        solve();
    }

    return 0;
}