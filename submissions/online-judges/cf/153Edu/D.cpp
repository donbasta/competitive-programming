#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(2);
    int cnt_10 = 0, cnt_01 = 0;
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == '1' && s[j] == '0')
                cnt_10++;
            else if (s[i] == '0' && s[j] == '1')
                cnt_01++;
        }
    }
    int ans = 2;
    if (cnt_10 == cnt_01)
        ans = 0;
    else {
        char l = '1', r = '0';
        string ss = s;
        if (cnt_01 < cnt_10) {
            swap(cnt_01, cnt_10);
            swap(l, r);
            for (auto& c : ss) {
                c = '1' - c + '0';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ss[i] == l && ss[j] == r && (2 * (j - i) == cnt_01 - cnt_10)) {
                    ans = 1;
                }
            }
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
        solve();
    }

    return 0;
}