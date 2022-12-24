#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n >> q;
        vector<int> D(n);
        for (int i = 1; i < n; i++) {
            cin >> D[i];
        }
        cout << "Case #" << tc << ": ";
        while (q--) {
            int s, k;
            cin >> s >> k;
            vector<pair<int, int>> le(s - 1);
            vector<pair<int, int>> ri(n - s);
            for (int i = 1; i < s; i++) {
                le[i - 1] = make_pair(D[i], i);
            }
            for (int i = n - 1; i >= s; i--) {
                ri[n - 1 - i] = make_pair(D[i], i);
            }
            int cur = 1, now = s;
            while (cur < k) {
                cur++;
                if (!le.empty() && !ri.empty()) {
                    if (le.back().first < ri.back().first) {
                        now = le.back().second;
                        le.pop_back();
                    } else {
                        now = ri.back().second + 1;
                        ri.pop_back();
                    }
                } else if (le.empty()) {
                    now = ri.back().second + 1;
                    ri.pop_back();
                } else if (ri.empty()) {
                    now = le.back().second;
                    le.pop_back();
                }
            }
            cout << now << ' ';
        }
        cout << '\n';
    }

    return 0;
}