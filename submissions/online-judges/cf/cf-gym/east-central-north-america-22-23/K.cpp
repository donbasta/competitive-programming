#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

string remove_space(string s) {
    string ret;
    for (auto c : s) {
        if (c == ' ') continue;
        ret.push_back(c);
    }
    return ret;
}

void solve() {
    string s;
    cin >> s;
    s = remove_space(s);
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