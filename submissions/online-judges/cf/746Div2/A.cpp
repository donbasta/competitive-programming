#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, H;

void solve() {
    cin >> n >> H;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end(), greater<>());
    int cyc = ar[0] + ar[1];
    int a = H / cyc;
    int b = H % cyc;
    int ans = 0;
    if (b == 0) {
        ans = 2 * a;
    } else if (b > ar[0]) {
        ans = 2 * a + 2;
    } else {
        ans = 2 * a + 1;
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