#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int a, b;
string s;

void solve() {
    cin >> a >> b;
    cin >> s;

    int n = a + b;
    vector<int> free;

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1]) {
            cout << -1 << '\n';
            return;
        }
        if (s[i] != '?') {
            s[n - 1 - i] = s[i];
            if (s[i] == '0') a -= 2;
            else b -= 2;
        } else if (s[n - 1 - i] != '?') {
            s[i] = s[n - 1 - i];
            if (s[i] == '0') a -= 2;
            else b -= 2;
        } else {
            free.emplace_back(i);
        }
        if (a < 0 || b < 0) {
            cout << -1 << '\n';
            return;
        }
    }
    int idx = 0;
    while (a > 1 && idx < free.size()) {
        a -= 2;
        s[free[idx]] = s[n - 1 - free[idx]] = '0'; 
        idx++; 
    }
    while (b > 1 && idx < free.size()) {
        b -= 2;
        s[free[idx]] = s[n - 1 - free[idx]] = '1'; 
        idx++;
    }
    if ((n % 2 == 0) && ((a != 0) || (b != 0))) {
        cout << -1 << '\n';
        return;
    }
    if (n & 1) {
        if (s[n / 2] == '?') {
            if (a > 0) s[n / 2] = '0', a--;
            else s[n / 2] = '1', b--;
        } else {
            if ((a > 0 && s[n / 2] == '1') || (b > 0 && s[n / 2] == '0')) {
                cout << -1 << '\n';
                return;
            }
            if (s[n / 2] == '1') b--;
            else a--;
        }
    }
    assert(a == 0 && b == 0);
    cout << s << '\n';
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