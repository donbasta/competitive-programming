#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll h, p;

void solve() {
    cin >> h >> p;
    ll cur = 1;
    ll dep = 1;
    ll time = 0;
    ll tot = (1LL << h) - 1;
    while (cur <= p) {
        tot -= cur;
        time++;
        cur <<= 1;
        dep++;
        if (dep > h) break;
    }
    time += (tot + p - 1) / p;
    cout << time << '\n';
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