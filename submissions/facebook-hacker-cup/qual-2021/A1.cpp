#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;
string s;
const int voc[] = {0, 4, 8, 14, 20};

void solve() {
    cin >> s;
    int n = (int)s.length();
    vector<int> cnt(26);
    for (auto c : s) {
        cnt[(c - 'A')]++;
    }
    int cnt_voc = 0;
    for (auto e : voc) {
        cnt_voc += cnt[e];
    }
    int cnt_cons = n - cnt_voc;
    int ans = INF;
    for (int i = 0; i < 26; i++) {
        if ((i == 0) || (i == 4) || (i == 8) || (i == 14) || (i == 20)) {
            ans = min(ans, (cnt_voc - cnt[i]) * 2 + cnt_cons);
        } else {
            ans = min(ans, (cnt_cons - cnt[i]) * 2 + cnt_voc);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}