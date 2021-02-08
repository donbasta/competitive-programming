#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q;
vector<int> h;

void solve() {
    cin >> n >> q;
    h.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    while (q--) {
        int tp, i;
        cin >> tp >> i;
        --i;
        if (tp == 1) {
            int a = i - 1, b = i + 1;
            int ans = 1;
            while (a >= 0 && h[a] <= h[i]) {
                ans++, a--;
            }
            while (b < n && h[b] <= h[i]) {
                ans++, b++;
            }
            cout << ans << '\n';
        } else if (tp == 2) {
            int x;
            cin >> x;
            h[i] = x;
        } else if (tp == 3) {
            int x, j;
            cin >> j >> x;
            j--;
            for (int k = i; k <= j; k++) h[k] = x;
        }   
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}