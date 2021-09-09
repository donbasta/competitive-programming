#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            cout << i + 1 << ' ' << i + 2 << '\n';
            return;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
    return;
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