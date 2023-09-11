#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int k;
    cin >> k;
    string ret;
    for (int i = 0; i < 26; i++) {
        int tmp = 1;
        int tot = 0;
        while ((tot + tmp) <= k) {
            tot += tmp;
            tmp++;
        }
        for (int j = 0; j < tmp; j++) {
            ret.push_back((char)(i + 'a'));
        }
        k -= tot;
        if (k == 0) break;
    }
    cout << ret << '\n';
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