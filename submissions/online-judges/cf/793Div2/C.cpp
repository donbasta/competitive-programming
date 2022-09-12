#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        mp[ar[i]]++;
    }
    if (n <= 2) {
        cout << 1 << '\n';
        return;
    }
    int a = 0, b = 0;
    for (auto e : mp) {
        if (e.second >= 2) a++;
        else if (e.second == 1) b++;
    }
    int ans = a + (b + 1) / 2;
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