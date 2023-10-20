#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int MOD = 1e9 + 7;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    vector<int> pre(n + 1);
    pre[0] = (pre[0] + ar[n - 1]) % MOD;
    pre[1] = (pre[1] - ar[n - 1]) % MOD;
    vector<pair<int, int>> itv;  //{end, val}
    itv.emplace_back(n - 1, ar[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        vector<pair<int, int>> tmp;
        int cur = ar[i];
        int bat = i;
        for (int j = 0; j < itv.size(); j++) {
            if (__gcd(itv[j].second, ar[i]) == cur) {
                bat = itv[j].first;
                continue;
            } else {
                tmp.emplace_back(bat, cur);
                cur = __gcd(itv[j].second, ar[i]);
                bat = itv[j].first;
            }
        }
        tmp.emplace_back(bat, cur);
        int st = i;
        for (auto e : tmp) {
            int bat = e.first;
            pre[st - i] = (pre[st - i] + e.second) % MOD;
            pre[bat - i + 1] = (pre[bat - i + 1] - e.second) % MOD;
            st = bat + 1;
        }
        itv.swap(tmp);
    }

    for (int i = 1; i < n; i++) {
        pre[i] = (pre[i] + pre[i - 1]) % MOD;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (1ll * ans * pre[i]) % MOD;
    }
    if (ans < 0) ans += MOD;
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
