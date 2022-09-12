#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int ra, ca, rb, cb;
        cin >> ra >> ca >> rb >> cb;
        pt[i].emplace_back(ra, ca);
        pt[i].emplace_back(rb, cb);
        pt[i + 1].emplace_back(ra + 1, ca);
        pt[i + 1].emplace_back(rb, cb + 1);
    }




    int m;
    cin >> m;
    while (m--) {
        int ra, ca, rb, cb;
        cin >> ra >> ca >> rb >> cb;
        for ()
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