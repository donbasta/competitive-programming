#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ld a = 1.3;
    ll b = 1;
    ll c = -9;
    ll d = c/2;
    cerr << c << ' ' << d;
    if (b >= a) {
        cerr << "True";
    }
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