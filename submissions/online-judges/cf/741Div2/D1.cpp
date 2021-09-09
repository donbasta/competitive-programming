#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q;
string s;

void solve() {
    cin >> n >> q;
    cin >> s;
    vector<vector<int>> sum(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        int cur = (s[i - 1] == '+' ? 1 : -1);
        sum[i][i & 1] += cur;
    }
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int lol = sum[i - 1][0] + sum[i][0] - (sum[i - 1][1] + sum[i][1]);
        mp[lol].push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt = r - l + 1;
        if (cnt & 1) {
            int haha = sum[r][0] + sum[l - 1][0] - sum[r][1] - sum[l - 1][1];
            assert (mp.find(haha) != mp.end());
            int pos = lower_bound(mp[haha].begin(), mp[haha].end(), l) - mp[haha].begin();
            if (pos == (int)mp[haha].size() || mp[haha][pos] > r) {
                assert(false);
            }
            cout << 1 << '\n';
            cout << mp[haha][pos] << '\n';
        } else {
            int A = sum[r][0] - sum[l - 1][0];
            int B = sum[r][1] - sum[l - 1][1];
            if (A == B) {
                cout << 0 << '\n';
            } else {
                int haha = sum[r][0] + sum[l][0] - sum[r][1] - sum[l][1];
                assert (mp.find(haha) != mp.end());
                int pos = lower_bound(mp[haha].begin(), mp[haha].end(), l + 1) - mp[haha].begin();
                if (pos == (int)mp[haha].size() || mp[haha][pos] > r) {
                    assert(false);
                }
                cout << 2 << '\n';
                cout << l << ' ' << mp[haha][pos] << '\n';
            }
        }
    }
    return;
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