#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;

void solve() {
    cin >> s;
    bool ok = false;
    for (auto c : s) {
        if (c == '0') {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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