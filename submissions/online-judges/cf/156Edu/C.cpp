#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    string s;
    cin >> s;
    ll pos;
    cin >> pos;
    int n = s.length();
    vector<int> buang;
    vector<int> tmp;
    tmp.push_back(0);
    for (int i = 1; i < n; i++) {
        while (!tmp.empty() && s[tmp.back()] > s[i]) {
            buang.push_back(tmp.back());
            tmp.pop_back();
        }
        tmp.push_back(i);
    }
    while (!tmp.empty()) {
        buang.push_back(tmp.back());
        tmp.pop_back();
    }
    ll cur = 0;
    int now = n;
    while (cur < pos) {
        cur += now;
        now--;
    }
    now++;
    cur -= now;
    int brp = pos - cur;
    vector<bool> masih(n, true);
    for (int i = 0; i < n - now; i++) {
        masih[buang[i]] = false;
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (masih[i]) x++;
        if (x == brp) {
            cout << s[i];
            return;
        }
    }
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