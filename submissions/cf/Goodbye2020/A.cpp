#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<bool> cnt(50);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cnt[ar[j] - ar[i]] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 50; i++) {
        ans += cnt[i];
    }
    cout << ans << '\n';
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