#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MX = 2e6;
const int T = 41;

void solve() {
    int P;
    cin >> P;
    if (P > MX) {
        cout << -1 << '\n';
        return;
    }
    int ni = P;
    vector<int> ve;
    int sum = 0;
    for (int i = 2; i * i <= ni; i++) {
        if (ni % i != 0) continue;
        while (ni % i == 0) {
            ni /= i;
            ve.push_back(i);
            sum += i;
        }
    }
    if (ni > 1) {
        ve.push_back(ni);
        sum += ni;
    }
    if (sum > T) {
        cout << -1 << '\n';
        return;
    }
    while (sum < T) {
        ve.push_back(1);
        sum++;
    }
    cout << ve.size() << ' ';
    for (auto e : ve) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}