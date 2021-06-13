#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n + 2), br(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        br[i] = ar[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ar[i] >= ar[i - 1] && ar[i] >= ar[i + 1]) {
            br[i] = max(ar[i - 1], ar[i + 1]);
            ans += (ar[i] - br[i]);
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        ans += abs(br[i] - br[i - 1]);
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