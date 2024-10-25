#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0;
    while (l < n && s[l] == 'B') {
        l++;
    }
    int r = n - 1;
    while (r >= 0 && s[r] == 'A') {
        r--;
    }
    if (l >= r) {
        cout << 0 << '\n';
        return;
    }
    cout << (r - l) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}