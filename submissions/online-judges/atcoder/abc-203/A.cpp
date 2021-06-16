#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a, b, c;

void solve() {
    cin >> a >> b >> c;
    if (a == b) cout << c;
    else if (a == c) cout << b;
    else if (b == c) cout << a;
    else cout << 0;
    cout << '\n';
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