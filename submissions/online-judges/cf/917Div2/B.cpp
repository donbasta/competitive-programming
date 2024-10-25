#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    int dis = 0;
    for (int i = 0; i < 26; i++) {
        dis += (cnt[i] > 0);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dis;
        cnt[s[n - 1 - i] - 'a']--;
        if (cnt[s[n - 1 - i] - 'a'] == 0) {
            dis--;
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
        el_psy_congroo();
    }

    return 0;
}