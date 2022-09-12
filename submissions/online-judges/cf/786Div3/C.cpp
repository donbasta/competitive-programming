#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s, t;
    cin >> s >> t;
    if (t == "a") {
        cout << 1 << '\n';
        return;
    }
    for (auto c : t) {
        if (c == 'a') {
            cout << -1 << '\n';
            return;
        }
    }
    cout << (1LL << ((int) s.length())) << '\n';
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