#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void rec(int n) {
    if (n == 1) {
        cout << 1 << ' ';
        return;
    }
    rec(n - 1);
    cout << n << ' ';
    rec(n - 1);
    return;
}

void solve() {
    int n;
    cin >> n;
    rec(n);
    cout << '\n';
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