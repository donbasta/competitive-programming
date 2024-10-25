#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto c : s) {
        cnt += (c == 'B');
    }
    if (cnt == k) {
        cout << 0 << '\n';
        return;
    } else if (cnt < k) {
        cout << 1 << '\n';
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += (s[i] == 'B');
            if (cnt - tmp + (i + 1) == k) {
                cout << (i + 1) << ' ' << 'B' << '\n';
                return;
            }
        }
    } else if (cnt > k) {
        cout << 1 << '\n';
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += (s[i] == 'B');
            if (tmp == cnt - k) {
                cout << (i + 1) << ' ' << 'A' << '\n';
                return;
            }
        }
    }
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