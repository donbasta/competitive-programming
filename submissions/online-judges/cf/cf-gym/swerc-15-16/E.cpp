#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MOD = (1 << 31) - 1;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        cin >> ar[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    set<int> se;
    se.insert(ar[1]);
    se.insert(ar[2]);
    if (ar[1] > ar[2]) swap(ar[1]. ar[2]);
    dp[ar[1]][ar[2]] = 1;
    for (int i = 3; i <= n + 1; i++) {
        for (auto j : se) {
            if (dp[min(j, ar[i])][max(j, ar[i])])
        }
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