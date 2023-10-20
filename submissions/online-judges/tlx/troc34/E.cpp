#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 1e5;

ll lcm(ll a, ll b) {
    return a * (b / __gcd(a, b));
}

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<ll> ar(n);
    vector<bool> ada(M + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ada[ar[i]] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (ar.back() % ar[i] != 0) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<ll> keep = {ar[0]};
    set<ll> se;
    se.insert(ar[0]);
    for (int i = 1; i < n; i++) {
        vector<ll> tmp;
        if (!se.count(ar[i])) {
            se.insert(ar[i]);
            keep.push_back(ar[i]);
        }
        for (auto c : se) {
            ll kpk = lcm(c, ar[i]);
            if (!ada[kpk]) {
                cout << -1 << '\n';
                return;
            }
            tmp.emplace_back(kpk);
        }
        for (auto e : tmp) {
            se.insert(e);
        }
    }
    cout << keep.size() << '\n';
    for (auto e : keep) {
        cout << e << ' ';
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