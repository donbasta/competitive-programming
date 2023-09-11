#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ret;
    for (int i = 1; i <= n; i += 2) {
        int tmp = i;
        while (tmp <= n) {
            ret.push_back(tmp);
            tmp *= 2;
        }
    }
    for (auto e : ret) cout << e << ' ';
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