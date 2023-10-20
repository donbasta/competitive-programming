#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    vector<int> ve;
    int x;
    while (cin >> x) {
        ve.emplace_back(x);
    }
    vector<int> comp;
    int last = ve[0];
    int len = 1;
    for (int i = 1; i < (int)ve.size(); i++) {
        if (ve[i] != last) {
            int cnt = len / 255;
            int sisa = len % 255;
            for (int i = 0; i < cnt; i++) {
                comp.emplace_back(255);
                comp.emplace_back(last);
            }
            if (sisa > 0) {
                comp.emplace_back(sisa);
                comp.emplace_back(last);
            }
            last = ve[i];
            len = 1;
        } else {
            len++;
        }
    }
    int cnt = len / 255;
    int sisa = len % 255;
    for (int i = 0; i < cnt; i++) {
        comp.emplace_back(255);
        comp.emplace_back(last);
    }
    if (sisa > 0) {
        comp.emplace_back(sisa);
        comp.emplace_back(last);
    }
    cout << comp.size() << '\n';
    for (auto e : comp) {
        cout << e << ' ';
    }
    for (int i = 0; i < 1337; i++) {
        cout << '\n';
    }
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