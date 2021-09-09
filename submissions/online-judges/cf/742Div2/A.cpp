#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n >> s;
    string ret;
    for (int i = 0; i < n; i++) {
        char c;
        if (s[i] == 'U') {
            c = 'D';
        } else if (s[i] == 'D') {
            c = 'U';
        } else {
            c = s[i];
        }
        ret.push_back(c);
    }
    cout << ret << '\n';
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