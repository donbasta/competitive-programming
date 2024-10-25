#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string tmp;
    for (int i = 1; i <= n; i++) {
        tmp += to_string(i);
    }
    int len = tmp.length();
    int ans = 0;
    for (int i = 0; i < len - 1; i++) {
        if (tmp[i] == '4' && tmp[i + 1] == '2') ans++;
    }
    cout << ans << '\n';
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