#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    vector<int> ve;
    for (int i = 0; i < n - 1; i++) {
        ve.push_back(abs(ar[i] - ar[i + 1]));
    }
    int sum = 0;
    sort(ve.begin(), ve.end());
    for (int i = 0; i < n - k; i++) {
        sum += ve[i];
    }
    cout << sum << '\n';
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