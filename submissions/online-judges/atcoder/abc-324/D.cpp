#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 1e6;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<int> freq(10);
    for (auto c : s) {
        freq[c - '0']++;
    }
    for (ll i = 0; i <= 4 * M; i++) {
        ll sq = i * i;
        string ss = to_string(sq);
        vector<int> cnt(10);
        for (auto c : ss) {
            cnt[c - '0']++;
        }
        bool ok = cnt[0] <= freq[0];
        for (int j = 1; j < 10; j++) {
            ok &= (cnt[j] == freq[j]);
        }
        ans += ok;
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