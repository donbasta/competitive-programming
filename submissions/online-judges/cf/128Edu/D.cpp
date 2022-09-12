#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> ar(n);
    ll sum = 0, emp = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] == 0) {
            emp++;
        } else {
            sum += ar[i];
        }
    }
    if ((emp == 0) && (sum != 0)) {
        cout << -1 << '\n';
        return;
    }
    if ((sum < (-k) * emp) || (sum > k * emp)) {
        cout << -1 << '\n';
        return;
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