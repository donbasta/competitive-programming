#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;

void solve() {
    cin >> s;
    int n = (int)s.length();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int dig = s[i] - '0';
        if (i & 1) a = a * 10 + (dig);
        else b = b * 10 + (dig);
    }
    // cerr << a << ' ' << b << '\n';
    ll ans = 1LL * (a + 1) * (b + 1);
    ans -= 2;
    // if ((a % 2 == 0) && (b % 2 == 0)) ans--;
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