#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int tmp = ar[i];
        for (int j = 2; j * j <= tmp; j++) {
            if (tmp % j != 0) continue;
            while (tmp % j == 0) {
                tmp /= j;
                cnt[j]++;
            }
        }
        if (tmp > 1) cnt[tmp]++;
    }
    bool ok = true;
    for (auto e : cnt) {
        ok &= (e.second % n == 0);
    }
    cout << (ok ? "YES" : "NO") << '\n';
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