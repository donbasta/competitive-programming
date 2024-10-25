#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    sort(ar.begin(), ar.end());
    int M = ar.back();
    ar.resize(unique(ar.begin(), ar.end()) - ar.begin());
    ll ans = 0;
    for (auto e : ar) {
        ans += 1ll * cnt[e] * (cnt[e] - 1) * (cnt[e] - 2);
        int bat = sqrt(M / e);
        for (int i = 2;; i++) {
            if (1ll * e * i * i > 1ll * M) break;
            if (cnt.count(e * i) && cnt.count(e * i * i)) {
                ans += 1ll * cnt[e] * cnt[e * i] * cnt[e * i * i];
            }
        }
    }
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