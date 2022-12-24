#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    set<int> se;

    for (int i = 1; i <= 10; i++) {
        se.insert(i);
    }

    for (auto e : se) {
        cerr << e << ' ';
    }
    cerr << '\n';

    auto it = se.upper_bound(6);
    int lol = 3;
    for (auto temp = it;; --temp) {
        cerr << *temp << '\n';
        if (*temp >= lol) se.erase(temp);
        if (temp == se.begin()) break;
    }
    for (auto e : se) {
        cerr << e << ' ';
    }
    // cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}