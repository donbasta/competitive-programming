#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    sort(s.begin(), s.end());
    vector<string> ret;
    int ans = 0;
    do {
        ans++;
        ret.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << ans << '\n';
    for (auto e : ret) {
        cout << e << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}