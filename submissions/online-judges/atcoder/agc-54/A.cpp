#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s;
    int n;
    cin >> n >> s;
    if (s[0] != s[n - 1]) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 1; i < n - 2; i++) {
        if ((s[i] != s[0]) && (s[i + 1] != s[n - 1])) {
            cout << 2 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
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