#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = (n - 1) / 2;
    char t = s[l];
    int r = l;
    if (n % 2 == 0) r++;
    while (l >= 0 && s[l] == t) {
        l--;
    }
    while (r < n && s[r] == t) {
        r++;
    }
    cout << (r - l - 1) << '\n';
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