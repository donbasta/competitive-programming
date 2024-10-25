#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    string s;
    cin >> s;
    set<string> se;
    for (char c = '1'; c <= '8'; c++) {
        string tmp = s;
        tmp[1] = c;
        se.insert(tmp);
    }
    for (char c = 'a'; c <= 'h'; c++) {
        string tmp = s;
        tmp[0] = c;
        se.insert(tmp);
    }
    se.erase(s);
    for (auto e : se) {
        cout << e << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}