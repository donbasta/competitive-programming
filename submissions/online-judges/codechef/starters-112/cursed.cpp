#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    multiset<ll> se;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        se.insert(ar[i]);
    }
    ll cur = 0;
    vector<ll> ret;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto ptr = se.upper_bound(cur);
        if (ptr != se.end()) {
            ret.push_back(*ptr);
            cur += *ptr;
            se.erase(ptr);
            ans++;
        } else {
            break;
        }
    }
    for (auto e : se) {
        ret.push_back(e);
    }
    cout << (n - ans) << '\n';
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
        el_psy_congroo();
    }

    return 0;
}