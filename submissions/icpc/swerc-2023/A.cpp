#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ar;
    ar.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ar.push_back(x);
    }
    ar.push_back(1440);
    int cek = 0;
    for (int i = 1; i < ar.size(); i++) {
        cek += (ar[i] - ar[i - 1]) / 120;
    }
    cout << (cek >= 2 ? "YES" : "NO") << '\n';
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