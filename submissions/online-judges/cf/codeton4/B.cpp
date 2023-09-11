#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ret;
    while (n > 1) {
        int rem = n % 4;
        if (rem == 1) {
            ret.push_back(1);
            n++;
        } else {
            ret.push_back(2);
            n--;
        }
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (auto e : ret) {
        cout << e << ' ';
    }
    cout << '\n';
    return;
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