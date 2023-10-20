#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<char> mx(n);
    mx[n - 1] = s.back();
    for (int i = n - 2; i >= 0; i--) {
        mx[i] = max(mx[i + 1], s[i]);
    }
    vector<vector<int>> ve(5, vector<int>(n)), pref_pos(5, vector<int>(n));
    for (char i = 'A'; i <= 'E'; i++) {
        if (s.back() == i) {
            ve[i - 'A'][n - 1] = 1;
        }
        for (int j = n - 2; j >= 0; j--) {
            if (s[j] != i) continue;
            if (mx[j + 1] > i)
                ve[i - 'A'][j] = -1;
            else
                ve[i - 'A'][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            pref_pos[j][i] = (i ? pref_pos[j][i - 1] : 0) + (ve[j][i] == 1);
        }
    }
    int ori = 0;
    int val[] = {1, 10, 100, 1000, 10000};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            ori += ve[j][i] * val[j];
        }
    }
    int ans = ori;
    for (int i = n - 1; i >= 0; i--) {
        int tmp = ori;
        char kan = (i == n - 1 ? 'A' : mx[i + 1]);
        if (ve[s[i] - 'A'][i] == 1) {
            tmp -= val[s[i] - 'A'];
        } else if (ve[s[i] - 'A'][i] == -1) {
            tmp += val[s[i] - 'A'];
        }
        for (char j = kan; j <= 'E'; j++) {
            int lmao = tmp;
            lmao += val[j - 'A'];
            for (char k = 'A'; k < j; k++) {
                lmao -= (i ? (2 * pref_pos[k - 'A'][i - 1] * val[k - 'A']) : 0);
            }
            ans = max(ans, lmao);
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
        solve();
    }

    return 0;
}