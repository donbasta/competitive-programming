#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int cnt = 0;
    int lol = -1;
    int t2 = 0, t3 = 0, t4 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') {
            if (cnt > 0) {
                if (cnt >= b && cnt < a) {
                    t2++;
                } else if (cnt >= a && cnt < 2 * b) {
                    t3++;
                } else if (cnt >= 2 * b) {
                    t4++;
                    lol = cnt;
                }
            }
            cnt = 0;
        } else if (s[i] == '.') {
            cnt++;
        }
    }
    if (cnt > 0) {
        if (cnt >= b && cnt < a) {
            t2++;
        } else if (cnt >= a && cnt < 2 * b) {
            t3++;
        } else if (cnt >= 2 * b) {
            t4++;
            lol = cnt;
        }
    }
    if (t2 > 0 || t4 > 1) {
        cout << "No" << '\n';
    } else if (t4 == 0) {
        cout << ((t3 & 1) ? "Yes" : "No") << '\n';
    } else {
        if (lol >= a + 4 * b - 1) {
            cout << "No" << '\n';
        } else if (t3 & 1) {
            if (max(a, lol - a - b + 1) <= min(lol - a, 2 * b - 1)) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else {
            if (lol >= 3 * a || lol <= a + 2 * b - 2) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}