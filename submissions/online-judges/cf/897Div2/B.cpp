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
    int gen = 0;
    int gan = 0;
    int beb = 0;
    for (int i = 0; i < (n / 2); i++) {
        if (s[i] == s[n - 1 - i])
            gen++;
        else
            gan++;
    }
    if (n & 1) {
        beb++;
    }
    string ret(n + 1, '0');
    for (int i = gan; i <= min(n, gan + 2 * gen); i += 2) {
        ret[i] = '1';
    }
    if (beb == 1) {
        for (int i = gan + 1; i <= min(n, gan + 2 * gen + 1); i += 2) {
            ret[i] = '1';
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