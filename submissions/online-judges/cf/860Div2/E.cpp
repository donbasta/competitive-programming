#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i + 1];
    }

    vector<bool> ok(n + 1);
    vector<int> depth(n + 1);

    for (int i = n; i >= 2; i--) {
        int next = i + ar[i] + 1;
        if (next == n + 1) {
            ok[i] = true;
            depth[i] = 1;
        } else if (next > n + 1) {
            ok[i] = false;
            depth[i] = 1;
        } else if (next <= n) {
            ok[i] = ok[next];
            depth[i] = depth[next] + 1;
        }
    }
    vector<int> ret;
    set<int> ada;
    for (int i = n - 1; i >= 1; i--) {
        if (ar[i] == 1) {
            if (ar[i + 1] == n - (i + 1)) {
                ret.push_back(0);
            } else {
                ret.push_back(1);
            }
        } else {
            if (ok[i + 1] && (depth[i + 1] == ar[i])) {
                ret.push_back(0);
            } else if (ok[i + 1] && (depth[i + 1] != ar[i])) {
                ret.push_back(1);
            } else if ((!ok[i + 1])) {
                if (depth[i + 1] >= ar[i]) {
                    ret.push_back(1);
                } else if (!ada.empty() && depth[i + 1] + *ada.begin() >= ar[i]) {
                    ret.push_back(1);
                } else {
                    ret.push_back(2);
                }
            } else {
                ret.push_back(2);
            }
        }
        if (ok[i + 1]) {
            ada.insert(depth[i + 1]);
        }
    }
    reverse(ret.begin(), ret.end());
    for (auto e : ret) {
        cout << e << ' ';
    }
    cout << '\n';
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