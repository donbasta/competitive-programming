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
    const function<bool(vector<int>&)> is_all_zero = [&](vector<int>& v) -> bool {
        vector<int> all_zero(n);
        return all_zero == v;
    };
    int t = 0, tmp = 1;
    while (tmp < n) {
        tmp <<= 1, t++;
    }
    if (is_all_zero(ar)) {
        cout << 0 << '\n';
        return;
    }
    int cur = 0;
    for (int i = t - 1; i >= 0; i--) {
        vector<int> tmp = ar;
        for (int j = 0; j < n; j++) {
            tmp[j] = ar[j] ^ ar[(j + (1 << i)) % n];
        }
        if (!is_all_zero(tmp)) {
            cur += (1 << i);
            ar = tmp;
        }
    }
    cout << cur + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}