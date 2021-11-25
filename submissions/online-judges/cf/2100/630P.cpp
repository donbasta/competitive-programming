#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ld PI = acos(-1);

void solve() {
    ld n, r;
    cin >> n >> r;
    ld haha = PI / (2 * n);
    ld u = r * sin(haha * 2) / sin(haha * 3);
    ld area = n * r * r * sin(haha * 4) / 2;
    ld rem = n * u * u * sin(haha * 6) / 2;
    area -= rem;
    cout << fixed << setprecision(9) << area;
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