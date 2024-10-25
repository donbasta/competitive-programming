#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += cnt[x];
        cnt[x]++;
    }
    ans += 1ll * cnt[1] * cnt[2];
    cout << ans << '\n';
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