#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool rev = false;
    for (int i = 0; i < k; i++) {
        if (s[i] != s[n - 1 - i]) {
            rev ^= 1;
        }
    }
    string ret = s.substr(k, n - 2 * k);
    if (rev) {
        reverse(ret.begin(), ret.end());
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}