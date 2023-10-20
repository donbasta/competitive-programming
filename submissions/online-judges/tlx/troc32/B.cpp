#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ve(n);
    ll sum = 0;
    int start = -1;
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
        if (ve[i] == 0) start = i;
    }
    assert(start != -1);
    ll len = 0;
    for (int i = start + 1; i < (start + n); i++) {
        if (ve[i % n] == 1)
            len++;
        else {
            sum += len * (len + 1) / 2;
            len = 0;
        }
    }
    sum += len * (len + 1) / 2;
    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}