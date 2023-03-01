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
    vector<bool> ve(n / 2);
    for (int i = 0; i < (n / 2); i++) {
        ve[i] = (s[i] != s[n - 1 - i]);
    }
    int cnt = 0;
    bool no = true;
    for (int i = 0; i < n / 2; i++) {
        if (no && ve[i]) {
            no = false;
            cnt++;
        } else if (!ve[i]) {
            no = true;
        }
    }
    cout << ((cnt <= 1) ? "Yes" : "No") << '\n';
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