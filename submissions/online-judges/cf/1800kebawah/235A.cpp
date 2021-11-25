#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n;
    cin >> n;
    if (n <= 2) {
        cout << n << '\n';
    } else if (n & 1) {
        cout << n * (n - 1) * (n - 2) << '\n';
    } else if (n == 4) {
        cout << 12 << '\n';
    } else {
        if (n % 3 != 0) {
            cout << (n) * (n - 1) * (n - 3) << '\n';
        } else {
            cout << (n - 1) * (n - 2) * (n - 3) << '\n';    
        } 
    }
    return;
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