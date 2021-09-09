#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a, b;

void solve() {
    cin >> a >> b;
    if (a < b) swap(a, b);
    set<int> se;
    int p = (a + b) / 2, q = (a + b + 1) / 2;
    for (int i = -b; i <= b; i += 2) {
        se.insert(p + i);
        se.insert(q + i);
    }
    cout << (int) se.size() << '\n';
    for (auto e : se) {
        cout << e << ' ';
    }
    cout << '\n';
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