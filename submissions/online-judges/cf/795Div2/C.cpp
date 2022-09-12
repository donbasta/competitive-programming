#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 2) {
        string cs = s;
        sort(cs.begin(), cs.end());
        if (k == 0) {
            cout << stoi(s) << '\n';
        } else {
            cout << stoi(cs) << '\n';
        }
        return;
    }

    int tot = 0;
    vector<int> cnt(2);
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        int dig = s[i] - '0';
        tot += (dig);
        cnt[dig]++;
        if (dig == 1) {
            r = i;
            if (l == -1) l = i;
        }
    }
    int orig = tot * 11 - (s[0] - '0') - 10 * (s.back() - '0');
    if (k == 0) {
        cout << orig << '\n';
        return;
    }
    int need = (l + (n - 1 - r));
    int ans;
    char p = s[0], q = s.back();
    if (cnt[1] == 0) {
        ans = 0;
    } else if (cnt[1] == 1) {
        if (n - 1 - r <= k) ans = 1;
        else if (l <= k) ans = 10;
        else ans = 11;
    } else if (cnt[1] >= 2) {
        if (k >= (need)) {
            ans = tot * 11 - 11;
        } else if (k < need) {
            if (p == '1' && q == '1') {
                ans = tot * 11 - 11;
            } else if (p == '1') {
                if (k >= (n - 1 - r)) ans = tot * 11 - 11;
                else ans = orig;
            } else if (q == '1') {
                if (k >= l) ans = tot * 11 - 11;
                else ans = orig; 
            } else {
                if (k >= (n - 1 - r)) ans = tot * 11 - 10;
                else if (k >= l) ans = tot * 11 - 1;
                else ans = orig;
            }
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
        solve();
    }
  
    return 0;
}