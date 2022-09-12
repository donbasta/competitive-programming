#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int deg = 0;
    bool leafExist = false;
    int cntZero = 0;
    for (auto c : s) {
        deg += (c - '0');
        leafExist |= (c == '1');
        cntZero += (c == '0');
    }
    if ((deg & 1) || (!leafExist)) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    if (cntZero == 0) {
        for (int i = 2; i <= n; i++) {
            cout << 1 << ' ' << i << '\n';
        }
        return;
    }
    int idx = 0;
    while (s[idx] != '0') {
        idx = (idx + 1) % n;
    }
    while (s[idx] != '1') {
        idx = (idx + n - 1) % n;
    }
    vector<pair<int, int>> edges;
    vector<int> ones;
    int start = idx, cnt = 1;
    for (int i = idx; cnt <= n; i = (i + 1) % n) {
        if (s[(i + 1) % n] == '0') {
            edges.emplace_back(i, (i + 1) % n);
        } else {
            ones.emplace_back(i);
        }
        cnt++;
    }
    for (int i = 1; i < ones.size(); i++) {
        edges.emplace_back(ones[0], ones[i]);
    }
    for (auto e : edges) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}