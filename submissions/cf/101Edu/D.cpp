#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<pair<int, int>> ve;
    int mx = n;
    if (n <= 10) {
        for (int i = 3; i < n; i++) {
            ve.emplace_back(i, i + 1);
        }
        while (mx > 1) {
            ve.emplace_back(n, 2);
            mx = (mx + 1) / 2;
        }
    } else {
        for (int i = 11; i < n; i++) {
            ve.emplace_back(i, i + 1);
        }
        while (mx > 1) {
            mx = (mx + 9) / 10;
            ve.emplace_back(n, 10);
        }
        for (int i = 4; i < 10; i++) {
            ve.emplace_back(i, i + 1);
        }
        ve.emplace_back(10, 3);
        ve.emplace_back(3, 10);
        ve.emplace_back(10, 2);
        ve.emplace_back(10, 2);
    }
    cout << (int)ve.size() << '\n';
    for (auto el : ve) {
        cout << el.first << ' ' << el.second << '\n';
    }
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