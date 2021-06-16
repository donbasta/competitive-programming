#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<int> a(n), cnt(3);
    for (auto& e : a) { 
        cin >> e; 
        cnt[e % 3]++;
    }
    int tot = n / 3;
    int ans = 0;
    int mx = *max_element(cnt.begin(), cnt.end());
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        if (cnt[i] == mx) {
            idx = i;
        }
    }
    ans += cnt[idx] - tot;
    cnt[(idx + 1) % 3] += cnt[idx] - tot;
    if (cnt[(idx + 1) % 3] >= tot) {
        ans += cnt[(idx + 1) % 3] - tot;
    } else {
        ans += 2 * (cnt[(idx + 2) % 3] - tot);
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