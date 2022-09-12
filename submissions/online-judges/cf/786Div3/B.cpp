#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    char a, b;
    cin >> a >> b;
    int na = a - 'a', nb = b - 'a';
    int ord = na * 26 + nb;
    ord -= na;
    if (nb < na) ord++;
    cout << ord << '\n';
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