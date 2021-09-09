#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int xs, ys, xt, yt;
    string command;
    cin >> xs >> ys;
    cin >> xt >> yt;
    cin >> command;

    map<char, int> cnt;
    for (auto c : command) {
        cnt[c]++;
    }
    int h1 = cnt['E'] - cnt['W'];
    int v1 = cnt['N'] - cnt['S'];
    int h2 = xt - xs;
    int v2 = yt - ys;

    int del = 0;
    if (h1 > h2) {
        int tmp = h1 - h2;
        if (cnt['E'] < tmp) {
            cout << -1 << '\n';
            return;
        }
        del += (tmp);
    } else if (h1 < h2) {
        int tmp = h2 - h1;
        if (cnt['W'] < tmp) {
            cout << -1 << '\n';
            return;
        }
        del += (tmp);
    }

    // cerr << del << '\n';

    if (v1 > v2) {
        int tmp = v1 - v2;
        if (cnt['N'] < tmp) {
            cout << -1 << '\n';
            return;
        }
        del += (tmp);
    } else if (v1 < v2) {
        int tmp = v2 - v1;
        if (cnt['S'] < tmp) {
            cout << -1 << '\n';
            return;
        }
        del += (tmp);
    }
    cout << del << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}