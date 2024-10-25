#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = 1;
    char cur = s[0];
    int ans = 0;
    vector<int> mx(26);
    for (int i = 1; i < n; i++) {
        if (s[i] == cur) {
            len++;
        } else {
            mx[cur - 'a'] = max(mx[cur - 'a'], len);
            len = 1;
            cur = s[i];
        }
    }
    mx[cur - 'a'] = max(mx[cur - 'a'], len);
    for (int i = 0; i < 26; i++) {
        ans += mx[i];
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