#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2 << '\n';
        return;
    }
    int p = (n / 6);
    int q = (n % 6);
    vector<int> lol = {0, 1, 1, 1, 2, 2};
    int ans = 2 * p + lol[q];
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
