#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    string s;
    cin >> s;
    string tmp;
    for (auto c : s) {
        if (c == 'C' && tmp.size() >= 2 && tmp.back() == 'B' && tmp[tmp.size() - 2] == 'A') {
            tmp.pop_back();
            tmp.pop_back();
        } else {
            tmp.push_back(c);
        }
    }
    cout << tmp << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}