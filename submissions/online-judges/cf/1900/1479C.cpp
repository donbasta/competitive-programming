#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int L, R;

void solve() {
    cin >> L >> R;
    int beda = R - L + 1;
    if (beda & (beda + 1)) {
        cout << "NO";
        return;
    }
    beda += 1;
    int sz = 1;
    while (beda >>= 1) { sz++; }
    sz++;
    int awal = 2;
    if (L == 1) {
        sz--;
        awal = 1;
    }
    vector<array<int, 3>> edges;
    for (int i = sz; i >= awal + 1; i--) {
        for (int j = awal; j < i; j++) {
            edges.push_back({j, i, 1 << (sz - i)});
        }
    }
    if (L > 1) {
        edges.push_back({1, 2, L - 1});
    }
    cout << "YES\n";
    cout << sz << " " << (int)edges.size() << '\n';
    for (auto e : edges) {
        cout << e[0] << ' ' << e[1] << ' ' << e[2] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}