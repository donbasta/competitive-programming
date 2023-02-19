#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    string s = to_string(n);
    string x, y;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        int dig = s[i] - '0';
        if (dig % 2 == 0) {
            int lol = dig / 2;
            x.push_back((char)(lol + '0'));
            y.push_back((char)(lol + '0'));
        } else {
            int lol = dig / 2, lol1 = dig - lol;
            if (cnt) {
                x.push_back((char)(lol + '0'));
                y.push_back((char)(lol1 + '0'));
                cnt = 0;
            } else {
                x.push_back((char)(lol1 + '0'));
                y.push_back((char)(lol + '0'));
                cnt = 1;
            }
        }
    }
    int ix = stoi(x), iy = stoi(y);
    cout << ix << ' ' << iy << '\n';
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