#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pre(n);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (s[i] == s[i - 1]);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << (pre[r] - pre[l]) << '\n';
    }
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