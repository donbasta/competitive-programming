#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pre(n), suf(n);
    vector<int> spre(n), ssuf(n);
    int tmp = 0, pr = 0;
    for (int i = 0; i < n; i++) {
        char cur = s[i];
        if (cur == '(')
            pr++;
        else {
            if (pr > 0) pr--, tmp += 2;
        }
        pre[i] = tmp, spre[i] = pr;
    }
    tmp = 0, pr = 0;
    for (int i = n - 1; i >= 0; i--) {
        char cur = s[i];
        if (cur == ')')
            pr++;
        else {
            if (pr > 0) pr--, tmp += 2;
        }
        suf[i] = tmp, ssuf[i] = pr;
    }
    int ans = min(suf[0], pre[n - 1]);
    // cerr << ans << '\n';
    for (int i = 0; i < n - 1; i++) {
        int lmao = pre[i] + suf[i + 1];
        lmao += 2 * min(ssuf[i + 1], spre[i]);
        ans = min(ans, lmao);
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