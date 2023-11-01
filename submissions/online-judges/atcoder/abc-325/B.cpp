#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> cnt(24);
    for (int i = 0; i < n; i++) {
        int w, x;
        cin >> w >> x;
        cnt[x] += w;
    }
    int ans = 0;
    for (int i = 0; i < 24; i++) {
        int cur = i;
        int tmp = 0;
        for (int k = 0; k < 9; k++) {
            tmp += cnt[cur];
            cur = (cur + 1) % 24;
        }
        ans = max(ans, tmp);
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