#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar.begin(), ar.end());
    int lo = 0, hi = INF;
    int ans = INF;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int pat_1 = ar[0] + mid;
        int atas_1 = pat_1 + mid;
        int bawah_2_idx = upper_bound(ar.begin(), ar.end(), atas_1) - ar.begin();
        if (bawah_2_idx >= n) {
            ans = mid, hi = mid - 1;
            continue;
        }
        int bawah_2 = ar[bawah_2_idx];
        int pat_2 = bawah_2 + mid;
        int atas_2 = pat_2 + mid;
        int bawah_3_idx = upper_bound(ar.begin(), ar.end(), atas_2) - ar.begin();
        if (bawah_3_idx >= n) {
            ans = mid, hi = mid - 1;
            continue;
        }
        int bawah_3 = ar[bawah_3_idx];
        int pat_3 = bawah_3 + mid;
        int atas_3 = pat_3 + mid;
        int lmao = upper_bound(ar.begin(), ar.end(), atas_3) - ar.begin();
        if (lmao >= n) {
            ans = mid, hi = mid - 1;
        } else {
            lo = mid + 1;
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
        solve();
    }

    return 0;
}