#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    ld ans = ar[n - 1];
    ld tmp = 0;
    for (int i = 0; i < n - 1; i++) {
        tmp += ar[i];
    }
    tmp = (tmp) / ((ld) (n - 1));
    ans += tmp;
    cout << fixed << setprecision(9) << ans << '\n';
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