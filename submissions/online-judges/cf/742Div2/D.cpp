#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void jawab(const vector<vector<int>>& a) {
    int n = (int)a.size();
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        for (auto j : a[i]) {
            ret[i] = (ret[i] * 10) + j;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
}

void solve() {
    string s;
    int n;
    cin >> s >> n;
    int k = (int) s.length();
    vector<int> is(k);
    int cap = 0;

    set<int> se;
    for (int i = 0; i < k; i++) {
        is[i] = (int) (s[i] - '0');
        cap += is[i];
        if (is[i] > 0 && (i != (k - 1))) se.insert(i);
    }
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            ans[i].push_back(0);
        }
    }

    while (cap < n) {
        int mn = *se.rbegin();
        is[mn]--;
        if (is[mn] == 0) se.erase(mn);
        for (int l = mn + 1; l < k; l++) {
            is[l] += 9;
            se.insert(l);
        }
        is[k - 1]++;
        cap += (9 * (k - 1 - mn) + 1);
    }

    int start = 0;
    for (int i = 0; i < k; i++) {
        if (start >= n) ans[0][i] = is[i];
        for (int j = start; j < min(n, start + is[i]); j++) {
            ans[j][i] = 1;
        }
        if ((start < n) && (start + is[i] > n)) {
            ans[n - 1][i] = (is[i] - (n - start - 1));
        }
        start = min(n, start + is[i]);
    }
    int carry = 0;
    for (int i = k - 1; i >= 0; i--) {
        ans[0][i] += carry;
        carry = 0;
        for (int j = 0; j < n; j++) {
            if (ans[j][i] > 10) {
                carry += (ans[j][i] / 10);
                ans[j][i] %= 10;
            }
        }
    }
    jawab(ans);
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