#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> cnt(2);
    for (auto c : s) {
        cnt[c - 'A']++;
    }
    bool ok = ((cnt[0] == (a + c + d)) && (cnt[1] == (b + c + d)));
    if (!ok) {
        cout << "NO" << '\n';
        return;
    }
    vector<int> sgn(n, -1);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            sgn[i] = 0;
        }
        if (s[i] == 'B' && s[i + 1] == 'A') {
            sgn[i] = 1;
        }
    }
    int j = 0, slot = 0;
    vector<vector<int>> length(2);
    for (int i = 0; i < n; i = j + 1) {
        j = i;
        if (sgn[i] == -1) {
            continue;
        }
        while ((j + 1 < n) && (sgn[j + 1] == (1 - sgn[j]))) {
            j++;
        }
        if (j == i) {
            if (sgn[i] == 0) {
                --c;
            } else if (sgn[i] == 1) {
                --d;
            }
        } else {
            if ((j - i + 1) & 1) {
                length[sgn[i]].emplace_back(j - i + 1);
            } else {
                slot += ((j - i + 1) / 2);
            }
        }
    }
    sort(length[0].begin(), length[0].end());
    sort(length[1].begin(), length[1].end());
    // reverse(length[0].begin(), length[0].end());
    // reverse(length[1].begin(), length[1].end());
    for (auto& e : length[0]) {
        if (c >= (e + 1) / 2) {
            c -= (e + 1) / 2;
            e = 0;
        }
    }
    for (auto& e : length[1]) {
        if (d >= (e + 1) / 2) {
            d -= (e + 1) / 2;
            e = 0;
        }
    }
    for (auto& e : length[0]) {
        if (e == 0) continue;
        int avail = (e + 1) / 2;
        assert(c < avail);
        if (c > 0) {
            e = e - 2 * c;
            c = 0;
        }
    }
    for (auto& e : length[1]) {
        if (e == 0) continue;
        int avail = (e + 1) / 2;
        assert (d < avail);
        if (d > 0) {
            e = e - 2 * d;
            d = 0;
        }
    }
    for (auto e : length[0]) {
        if (e == 0) continue;
        int avail1 = (e + 1) / 2;
        int avail2 = (e - 1) / 2;
        if (c >= avail1) {
            c -= avail1;
        }  else if (c > 0 && c < avail1) {
            d = max(0LL, d - (avail2 - c));
            c = 0;
        }  else if (c == 0) {
            d = max(0LL, d - avail2);
        }
    }
    for (auto e : length[1]) {
        if (e == 0) continue;
        int avail1 = (e + 1) / 2;
        int avail2 = (e - 1) / 2;
        if (d >= avail1) {
            d -= avail1;
        }  else if (d > 0 && d < avail1) {
            c = max(0LL, c - (avail2 - d));
            d = 0;
        }  else if (d == 0) {
            c = max(0LL, c - avail2);
        }
    }
    cout << ((c + d) > slot ? "NO" : "YES") << '\n';
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