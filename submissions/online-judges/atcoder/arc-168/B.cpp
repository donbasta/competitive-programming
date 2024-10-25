#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    int ks = 0;
    vector<int> ar(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ks ^= ar[i];
        cnt[ar[i]]++;
    }
    int mx = 0;
    for (auto e : cnt) {
        if (e.second % 2 == 0) continue;
        mx = max(mx, e.first);
    }
    int ans;
    if (ks != 0) {
        ans = -1;
    } else {
        if (mx == 0)
            ans = 0;
        else
            ans = (mx - 1);
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