#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string n;
    cin >> n;
    int step = 0;
    while (n.length() > 1) {
        ll tmp = 1;
        for (auto c : n) {
            tmp = tmp * (c - '0');
        }
        n = to_string(tmp);
        step++;
    }
    cout << step << '\n';
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