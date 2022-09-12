#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "1\n1 1\n";
        return;
    }
    if (n == 3) {
        cout << "2\n1 1\n1 2\n";
        return;
    } 
    vector<pair<int, int>> ans;
    ans.emplace_back(1, 1);
    ans.emplace_back(2, 3);
    ans.emplace_back(3, 2);

    set<int> se;
    for (int i = 4; i <= n; i++) {
        se.insert(i);
    }
    int sel = 2;
    while (sel < n) {
        int mn = *se.begin();
        if (n - (mn + 1) < sel) {
            if (n - (mn) >= sel) {
                ans.emplace_back(n, n);
            }
            break;
        }
        se.erase(se.begin());
        int nx = mn + sel;
        se.erase(nx);
        ans.emplace_back(mn, nx);
        ans.emplace_back(nx, mn);
        sel++;
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first << ' ' << e.second << '\n';
    }
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