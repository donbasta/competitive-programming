#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    ll k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    ll val = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            val += (1ll << (n - 1 - i));
    }
    ll now = val;
    reverse(s.begin(), s.end());
    deque<char> de;
    for (auto c : s) de.push_back(c);
    int ans = 0;
    while (now > k) {
        assert(de.size() > 1);
        assert(de.back() == '1');
        if (de[de.size() - 2] == '0') {
            now /= 2;
            de.pop_front();
        } else if (de[de.size() - 2] == '1') {
            ll x = now - now / 2;
            if (x > (1ll << (de.size() - 1))) {
                now /= 2;
                de.pop_front();
            } else {
                now -= (1ll << (de.size() - 1));
                de.pop_back();
            }
        }
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}