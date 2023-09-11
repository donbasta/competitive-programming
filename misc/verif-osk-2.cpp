#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int cnt;
    cin >> cnt;
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            for (int k = 0; k < cnt; k++) {
                for (int l = 0; l < cnt; l++) {
                    if (i == k && j == l) continue;
                    pair<int, int> p1 = make_pair(i, j);
                    pair<int, int> p2 = make_pair(k, l);
                    pair<int, int> p3 = make_pair(p2.first + (j - l), p2.second + (k - i));
                    pair<int, int> p4 = make_pair(p3.first + (i - k), p3.second + (j - l));
                    if (p3.first < 0 || p3.first >= cnt || p3.second < 0 || p3.second >= cnt) continue;
                    if (p4.first < 0 || p4.first >= cnt || p4.second < 0 || p4.second >= cnt) continue;
                    ans++;
                }
            }
        }
    }
    ans /= 4;
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