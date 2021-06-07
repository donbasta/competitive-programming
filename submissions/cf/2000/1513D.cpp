#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, p;

void solve() {
    cin >> n >> p;
    vector<int> ve(n);
    vector<pair<int, int>> pos;
    int idx = 0;
    for (auto& e : ve) {
        cin >> e;
        pos.emplace_back(e, idx++);
    }
    sort(pos.begin(), pos.end());
    ll ans = 0;

    vector<bool> udah(n, false);
    int rem = n - 1;
    for (auto e : pos) {
        int val = e.first;
        int loc = e.second;
        // cerr << val << ' ' << loc << '\n';
        if (val > p) break;
        if (udah[loc]) continue;
        int l = loc - 1;
        int cnt = 0;
        while (l >= 0) {
            if (ve[l] % val == 0 && udah[l]) {
                // cerr << l << ' ' << loc << '\n';
                rem--;
                cnt++;
                ans += val;
                break;
            }
            if (ve[l] % val == 0) {
                // cerr << l << ' ' << loc << '\n';
                rem--;
                cnt++;
                ans += val;
                udah[l] = true;
                l--;
            } else {
                break;
            }
        }
        int r = loc + 1;
        while (r < n) {
            if (ve[r] % val == 0 && udah[r]) {
                // cerr << r << ' ' << loc << '\n';
                rem--;
                cnt++;
                ans += val;
                break;
            }
            if (ve[r] % val == 0) {
                // cerr << r << ' ' << loc << '\n';
                rem--;
                cnt++;
                ans += val;
                udah[r] = true;
                r++;
            } else {
                break;
            }
        }
        if (cnt) udah[loc] = true;
    }  
    // cerr << rem << " hehe rem\n";
    ans += 1LL * rem * p;
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