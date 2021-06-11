#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    int mx = 0, mn = 101;
    int mxi = -1, mni = 1;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] > mx) {
            mx = ar[i];
            mxi = i;
        }
        if (ar[i] < mn) {
            mn = ar[i];
            mni = i;
        }
    }
    if (mxi > mni) swap(mxi, mni);
    int ans = min({mxi + 1 + n - mni, mni + 1, n - mxi});
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