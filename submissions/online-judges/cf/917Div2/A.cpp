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
    bool zer = false;
    int neg = 0;
    for (auto& e : ar) {
        cin >> e;
        if (e == 0) zer = true;
        neg += (e < 0);
    }
    if (zer) {
        cout << 0 << '\n';
        return;
    }
    if (neg & 1) {
        cout << 0 << '\n';
        return;
    }
    cout << 1 << '\n';
    cout << 1 << ' ' << 0 << '\n';
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