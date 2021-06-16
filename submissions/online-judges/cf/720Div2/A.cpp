#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll a, b;

void solve() {
    cin >> a >> b;
    if (b == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << a*b << " " << a*(b+1) << " " << a*(2*b+1) << "\n";
    }
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