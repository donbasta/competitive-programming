#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (auto c : s) cnt[c - '0']++;
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    while (cnt.back() == 0) {
        cnt.pop_back();
    }
    int ans = -1;
    if (cnt == vector<int>{1, 1, 1, 1}) {
        ans = 4;
    } else if (cnt == vector<int>{2, 1, 1}) {
        ans = 4;
    } else if (cnt == vector<int>{3, 1}) {
        ans = 6;
    } else if (cnt == vector<int>{2, 2}) {
        ans = 4;
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