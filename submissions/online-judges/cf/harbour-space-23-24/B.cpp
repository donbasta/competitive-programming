#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k & 1) {
        vector<string> tmp(2);
        for (int i = 0; i < n; i++) {
            tmp[i & 1].push_back(s[i]);
        }
        sort(tmp[0].begin(), tmp[0].end());
        sort(tmp[1].begin(), tmp[1].end());
        string ret(n, '\0');
        int idx = 0;
        for (int i = 0; i < n; i += 2) ret[i] = tmp[0][idx++];
        idx = 0;
        for (int i = 1; i < n; i += 2) ret[i] = tmp[1][idx++];
        cout << ret << '\n';
    } else {
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
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