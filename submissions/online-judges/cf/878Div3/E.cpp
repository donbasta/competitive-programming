#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int n = s[0].length();
    set<int> diff_idx;
    for (int i = 0; i < n; i++) {
        if (s[0][i] != s[1][i]) diff_idx.insert(i);
    }
    int t, q;
    cin >> t >> q;
    vector<int> unblock(t + q + 1, -1);
    for (int i = 0; i < q; i++) {
        if (unblock[i] != -1) {
            if (s[0][unblock[i]] != s[1][unblock[i]]) diff_idx.insert(unblock[i]);
        }

        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos;
            cin >> pos;
            --pos;
            if (diff_idx.count(pos)) diff_idx.erase(pos);
            unblock[i + t] = pos;
        } else if (tp == 2) {
            int a, posa, b, posb;
            cin >> a >> posa >> b >> posb;
            --a, --b, --posa, --posb;
            if (s[a][posa] != s[1 - a][posa]) diff_idx.erase(posa);
            if (s[b][posb] != s[1 - b][posb]) diff_idx.erase(posb);
            swap(s[a][posa], s[b][posb]);
            if (s[a][posa] != s[1 - a][posa]) diff_idx.insert(posa);
            if (s[b][posb] != s[1 - b][posb]) diff_idx.insert(posb);
        } else if (tp == 3) {
            if (diff_idx.empty()) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
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
        solve();
    }

    return 0;
}