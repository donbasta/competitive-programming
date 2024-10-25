#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const char H = '-';

void el_psy_congroo() {
    string s;
    cin >> s;
    int n = s.length();
    int tot = 0;
    int cur = 10;

    int cnt_hyphen = 0;
    int cnt_dig = 0;
    for (int i = 0; i < n; i++) {
        cnt_hyphen += s[i] == H;
        cnt_dig += s[i] != H;
    }
    if (cnt_hyphen == 3 && s[n - 2] != H) {
        cout << "invalid" << '\n';
        return;
    }
    if (cnt_dig != 10) {
        cout << "invalid" << '\n';
        return;
    }
    // cerr << s << '\n';

    for (int i = 0; i < n; i++) {
        if (s[i] == '-') continue;
        int dig = ((s[i] == 'X') ? 10 : (s[i] - '0'));
        tot = (tot + (cur * dig)) % 11;
        cur--;
    }
    if (tot != 0) {
        cout << "invalid" << '\n';
        return;
    }
    string nw = "978";
    nw.push_back(H);
    nw += s;
    n = nw.length();
    cur = 1;
    tot = 0;
    for (int i = 0; i < n - 1; i++) {
        if (nw[i] == '-') continue;
        if (nw[i] < '0' || nw[i] > '9') {
            cout << "invalid" << '\n';
            return;
        }
        tot = (tot + (cur * (nw[i] - '0'))) % 10;
        cur = ((cur == 1) ? 3 : 1);
    }
    int need = (10 - tot) % 10;
    nw.back() = (char)(need + '0');
    cout << nw << '\n';
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