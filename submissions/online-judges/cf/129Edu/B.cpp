#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int m;
    cin >> m;
    vector<int> br(m);
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> br[i];
        sum = (sum + br[i]) % n;
    }
    sum %= n;
    if (sum < 0) sum += n;
    cout << ar[sum] << '\n';
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