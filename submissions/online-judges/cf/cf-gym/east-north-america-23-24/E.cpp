#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 4e18;

void el_psy_congroo() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] != 'E' && s[i] != 'O') {
            cout << "INVALID" << '\n';
            return;
        }
        if (i < n - 1 && s[i] == 'O' && s[i + 1] == 'O') {
            cout << "INVALID" << '\n';
            return;
        }
        if (i == n - 1 && s[i] == 'E') {
            cout << "INVALID" << '\n';
            return;
        }
    }
    const int B = 60;
    for (int i = 0; i <= B; i += 2) {
        ll cur = (1ll << i);
        cur = (cur - 1) / 3;
        bool ok = true;
        for (int j = n - 1; j >= 0; j--) {
            int par = (s[j] == 'E') ? 0 : 1;
            if ((cur & 1) != par) {
                ok = false;
                break;
            }
            if (j > 0) {
                int nx_par = (s[j - 1] == 'E') ? 0 : 1;
                if (nx_par == 1) {
                    if (cur % 3 != 1) {
                        ok = false;
                        break;
                    }
                    cur = (cur - 1) / 3;
                } else {
                    cur *= 2;
                }
            }
        }
        if (ok) {
            cout << cur << '\n';
            return;
        }
    }
    assert(false);
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