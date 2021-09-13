#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n >> s;
    int block = 0;
    char last = '-';
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') {
            continue;
        } else if (last == '-') {
            last = s[i];
            block++;
        } else if (s[i] != last) {
            last = s[i];
            block++;
        }
    }
    int ans = max(0, block - 1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
  
    return 0;
}