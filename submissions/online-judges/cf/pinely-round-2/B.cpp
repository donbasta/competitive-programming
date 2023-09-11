#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
        pos[p[i]] = i;
    }
    int block = 0;
    for (int i = 1; i < n; i++) {
        if (pos[i] < pos[i - 1]) {
            block++;
        }
    }
    cout << block << '\n';
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