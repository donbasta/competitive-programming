#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    multiset<int> se;
    se.insert(ar[0]);
    for (int i = 1; i < n; i++) {
        int x = ar[i], y = ar[i - 1];
        if (x < y) swap(x, y);
        auto ptr = se.lower_bound(x);
        if (ptr != se.begin()) {
            --ptr;
            if (*ptr > y) {
                cout << "NO" << '\n';
                return;
            }
        }
        se.insert(ar[i]);
    }
    cout << "YES" << '\n';
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