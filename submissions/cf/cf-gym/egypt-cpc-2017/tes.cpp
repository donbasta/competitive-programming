#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld PI = acos(-1);

void solve() {
    ld a = (300 * sqrtl(3) - PI * 100);
    ld b = (1 + ((ld)1)/4 + ((ld)1)/16);
    ld cek = a * b;
    cout << fixed << setprecision(9) << cek << '\n';
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