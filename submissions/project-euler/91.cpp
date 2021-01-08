#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll n;
ll ans;

/**

0, 0
i, j
y = (-i / j)x + c
j = (-i^2 / j) + c
c = (j^2 + i^2) / j

jy = (-i)x + (j^2 + i^2)
jy + ix = (j^2 + i^2);

x = i - kj'
y = j + ki'

ui = vj -> ui' = vj' -> v = ki', u = kj'

i - kj' >= 0 -> k <= i/j'
i - kj' <= n -> k >= (i-n) / j'
j + ki' >= 0 -> k >= -j / i'
j + ki' <= n -> 

*/


void solve() {
    cin >> n;
    ans = n * n * 3;
    cerr << n << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 0 && j == 0) continue;
            ll fpb = __gcd(i, j);
            ll is = i / fpb, js = j / fpb;
            ll atas = min (i/js, (n - j)/is);
            ll bawah = max((i - n)/js, (-j)/is);
            cerr << i << ' ' << j << ' ' << atas << ' ' << bawah << '\n';
            ans += (max(0LL, atas-bawah+1));
            ans--;
        }
    }
    cout << ans << '\n';
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