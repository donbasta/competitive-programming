#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, xb, yb;
int xa, ya, za;

map<pair<int, int>, int> cnt;

void solve() {
    cin >> n >> xb >> yb;
    int base = 0;
    for (int i = 0; i < n; i++) {
        cin >> xa >> ya >> za;
        xa -= xb, ya -= yb;
        if (xa == 0 && ya == 0) {
            base += za;
            continue;
        }
        int fpb = __gcd(xa, ya);
        fpb = abs(fpb);
        xa /= fpb, ya /= fpb;
        cnt[make_pair(xa, ya)] += za;
    }

    int mx = 0;
    for (auto i : cnt) {
        mx = max(mx, i.second);
    }
    cout << mx + base << '\n'; 
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