#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<string> ss(n);
    vector<unordered_map<int, int>> cnt(6);
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
        int len = ss[i].length();
        int tmp = 0;
        for (auto c : ss[i]) {
            tmp += (c - '0');
        }
        cnt[len][tmp]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int len = ss[i].length();
        vector<int> pref(len), suf(len);
        pref[0] = ss[i][0] - '0';
        for (int j = 1; j < len; j++) {
            pref[j] = pref[j - 1] + (ss[i][j] - '0');
        }
        suf[len - 1] = ss[i][len - 1] - '0';
        for (int j = len - 2; j >= 0; j--) {
            suf[j] = suf[j + 1] + (ss[i][j] - '0');
        }
        // a0 ... a(len-1)
        for (int j = 1; j <= 5; j++) {
            if ((len + j) & 1) continue;
            int mid = (len + j) / 2;
            if (mid >= len) continue;

            int ki = pref[mid - 1];
            int ka = pref[len - 1] - ki;
            ans += cnt[j][ki - ka];

            ka = suf[len - mid];
            ki = suf[0] - ka;
            ans += cnt[j][ka - ki];
        }
    }
    for (int i = 1; i <= 5; i++) {
        for (auto c : cnt[i]) {
            ans += 1ll * c.second * c.second;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}