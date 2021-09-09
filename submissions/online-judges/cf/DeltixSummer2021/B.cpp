#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n), cnt(2);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[(ar[i] & 1)]++;
    }
    int a = cnt[0], b = cnt[1];
    if (a < b) swap(a, b);
    if ((a != (n + 1) / 2) || (b != (n / 2))) {
        cout << -1 << '\n';
        return;
    }
    ll ans = 0;
    int cur = 0;
    if (n & 1) {
        if (cnt[0] == (n + 1) / 2) {
            for (int i = 0; i < n; i++) {
                if (ar[i] % 2 == 0) {
                    ans += abs(cur - i);
                    cur += 2;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (ar[i] % 2 == 1) {
                    ans += abs(cur - i);
                    cur += 2;
                }
            }
        }
    } else {
        ll t1 = 0, t2 = 0;
        int c1 = 0, c2 = 1;
        for (int i = 0; i < n; i++) {
            if (ar[i] % 2 == 0) {
                t1 += abs(c1 - i);
                c1 += 2;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ar[i] % 2 == 0) {
                t2 += abs(c2 - i);
                c2 += 2;
            }
        }
        ans = min(t1, t2);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}