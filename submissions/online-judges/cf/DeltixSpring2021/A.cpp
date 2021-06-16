#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;
string s;

void solve() {
    cin >> n >> m >> s;
    int l = -1, r = -1;
    int last = 1;
    vector<pair<int, int>> ve;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (last) l = i;
            r = i;
            last = 0;
        } else if (s[i] == '1') {
            if (!last) ve.emplace_back(l, r);
            last = 1;
            continue;
        }
    }
    if (!last) ve.emplace_back(l, r);
    if (l == 0 && r == n - 1) {
        cout << s << '\n';
        return;
    }
    for (auto& loc : ve) {
        l = loc.first, r = loc.second;
        int len = r - l + 1;
        int mx, cnt;
        if (l == 0) {
            mx = r - l + 1, cnt = min(mx, m);
            for (int i = r; cnt > 0; i--) {
                s[i] = '1', cnt--;
            }
        } else if (r == n - 1) {
            mx = r - l + 1, cnt = min(mx, m);
            for (int i = l; cnt > 0; i++) {
                s[i] = '1', cnt--;
            }
        } else {
            mx = (r - l + 1) / 2, cnt = min(mx, m);
            for (int p = l, q = r; cnt > 0; p++, q--) {
                s[p] = s[q] = '1', cnt--;
            }
        }
    }
    cout << s << '\n';
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