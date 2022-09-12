#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;

    vector<int> ar(n);
    map<int, int> mp;
    int xr = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mp[ar[i]] = true;
        xr ^= ar[i];
    }
    if (mp.find(xr) != mp.end()) {
        cout << "Win" << '\n';
        return;
    }
    // cerr << xr << '\n';
    if (n <= 4) {
        if (n & 1) {
            cout << "Win" << '\n';
        } else {
            cout << "Lose" << '\n';
        }
        return;
    }
    if (n & 1) {
        cout << "Win" << '\n';
        return;
    }
    cout << "Lose" << '\n';
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