#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    cin >> n;
    if (n == 5) {
        brute_force();
    }
    array<int, 3> mn = process_five_mn(1, 2, 3, 4, 5);
    for (int i = 6; i <= n; i += 2) {
        if (i < n) {
            mn = process_five_mn(mn[0], mn[1], mn[2], i, i + 1);
        } else if (i == n) {
            mn = process_five_mn(mn[0], mn[1], mn[2], n, _);
        }
    }
    array<int, 3> mx = process_five_mx(1, 2, 3, 4, 5);
    for (int i = 6; i <= n; i += 2) {
        if (i < n) {
            mn = process_five_mx(mn[0], mn[1], mn[2], i, i + 1);
        } else if (i == n) {
            mn = process_five_mx(mn[0], mn[1], mn[2], n, _);
        }
    }
    process_five_mx()
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