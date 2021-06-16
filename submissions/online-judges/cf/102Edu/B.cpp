#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s, t;

void solve() {
    cin >> s >> t;
    int ss = (int)s.length();
    int tt = (int)t.length();
    int dd = __gcd(ss, tt);
    for (int i = 1; i * i <= dd; i++) {
        
    }

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