#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    cin >> n >> m;
    vector<pair<int, int>> sw;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        sw.emplace_back(x, y);
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