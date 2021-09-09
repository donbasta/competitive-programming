#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;
string rb = "RB";

void solve() {
    cin >> n >> s;
    int l = 0;
    while (l < n && s[l] == '?') l++;
    if (l == n) {
        for (int i = 0; i < n; i++) {
            if (i & 1) s[i] = 'B';
            else s[i] = 'R';
        }
    } else {
        char t = s[l];
        int id;
        if (t == 'B') id = 0;
        else id = 1;
        for (int i = l - 1; i >= 0; i--) {
            s[i] = rb[id];
            id ^= 1;
        } 
        for (int i = l + 1; i < n; i++) {
            if (s[i] == '?') {
                if (s[i - 1] == 'B') s[i] = 'R';
                else s[i] = 'B';
            }
        }
    }
    cout << s << '\n';
    return;
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