#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    // cerr << "error";
    if (a == 0 && c == 0) {
        cout << 0 << '\n';
        return;
    }
    if (a == 0 || c == 0) {
        cout << 1 << '\n';
        return;
    }
    ll p = a * d;
    ll q = b * c;
    if (p == q) {
        cout << 0 << '\n';
        return;
    }
    if ((p % q == 0) || (q % p == 0)) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
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
