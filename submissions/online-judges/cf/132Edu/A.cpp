#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int INF = 2e9;
 
void solve() {
    int cur;
    cin >> cur;
    vector<int> a(4);
    for (int i = 1; i <= 3; i++) {
        cin >> a[i];
    }
    vector<bool> ok(4);
    while (cur != 0) {
        ok[cur] = true;
        cur = a[cur];
    }
    int open = 0;
    for (int i = 1; i <= 3; i++) {
        open += ok[i];
    }
    if (open < 3) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
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
