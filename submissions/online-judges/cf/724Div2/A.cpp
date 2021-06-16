#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n);
    bool neg = false;
    for (auto& e : ar) {
        cin >> e;
        if (e < 0) neg = true;
    }
    if (neg) {
        cout << "no" << '\n';
        return;
    }
    cout << "yes" << '\n';
    cout << 101 << '\n';
    for (int i = 0; i <= 100; i++) {
        cout << i << ' ';
    }
    cout << '\n';
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