#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    string ans(n, ' ');
    if (n & 1) {
        for (int i = 0; i < n; i++) {
            if (i & 1)
                ans[i] = 'a';
            else
                ans[i] = 'b';
        }
    } else {
        int col = 1;
        while (n % col == 0) col++;
        assert(col <= 26);
        vector<char> ch(col);
        for (int i = 0; i < col; i++) {
            ch[i] = i + 'a';
        }
        for (int i = 0; i < n; i++) {
            ans[i] = ch[i % col];
        }
    }
    cout << ans << '\n';
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