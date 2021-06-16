#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fpow(ll a, ll b){
    ll ret = 1;
    while (b){
        if (b & 1){
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a){
    return fpow(a, MOD - 2);
}

void solve() {
    ll t = 2 - inv(100000);
    t = t % MOD;
    if (t < 0) t += MOD;
    cout << t << '\n';
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