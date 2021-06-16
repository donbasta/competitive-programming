#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;

ll F(int x) {
    return 1LL * x * (x + 1) / 2;
}

void solve() {
    cin >> s;
    int l0 = -1, l1 = -1;
    int s0 = 0, s1 = 0;
    int p0 = -1, p1 = -1;
    bool a0 = 0, a1 = 0;
    int n = (int) s.length();
    ll ans = 0;
    int last = 0, start = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') continue;
        if (s[i] == '0') {
            if (!a0) {
                a0 = true;
                s0 = (i & 1);
                p0 = i;
                if (a1 && s0 == s1) {
                    ans += (F(i - last) - F(start - last));
                    last = p1 + 1;
                    start = i;
                    a1 = false;
                }
                continue;
            }

            int cur = (i & 1);
            if (s0 == cur && ((a1 && s1 != cur) || !a1)) {
                p0 = i;
                continue;
            }
            ans += (F(i - last) - F(start - last));
            if (s0 != cur) last = max(last, p0 + 1);
            if (a1 && s1 == cur) last = max(last, p1 + 1);
            s0 = cur;
            p0 = i;
            start = i;
            a1 = false;
        } else if (s[i] == '1') {
            if (!a1) {
                a1 = true;
                s1 = (i & 1);
                p1 = i;
                if (a0 && s0 == s1) {
                    ans += (F(i - last) - F(start - last));
                    last = p0 + 1;
                    start = i;
                    a0 = false;
                }
                continue;
            }

            int cur = (i & 1);
            if (s1 == cur && ((a0 && s0 != cur) || !a0)) {
                p1 = i;
                continue;
            }
            ans += (F(i - last) - F(start - last));
            if (s1 != cur) last = max(last, p1 + 1);
            if (a0 && s0 == cur) last = max(last, p0 + 1);
            s1 = cur;
            p1 = i;
            start = i;
            a0 = false;
        }
    }
    ans += (F(n - last) - F(start - last));
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