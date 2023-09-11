#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<int> ve(3);
    for (int i = 0; i < n; i++) {
        ve[s[i] - 'A']++;
        if (ve[0] > 0 && ve[1] > 0 && ve[2] > 0) {
            cout << i + 1 << '\n';
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}