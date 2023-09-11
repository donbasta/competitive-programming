#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ret;
    char cur = s[0];
    bool reset = false;
    for (int i = 1; i < n; i++) {
        if (reset) {
            cur = s[i];
            reset = false;
        } else if (s[i] == cur) {
            ret.push_back(cur);
            reset = true;
        }
    }
    cout << ret << '\n';
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