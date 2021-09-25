#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n >> s;
    vector<int> ve;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ve.push_back(i);
        }
    }
    int sz = (int) ve.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(ve.begin(), ve.end(), i) - ve.begin();
        if (j == sz) {
            ans += (i - ve[sz - 1]);
        } else if (j == 0) {
            ans += (ve[0] - i);
        } else {
            ans += min(ve[j] - i, i - ve[j - 1]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}