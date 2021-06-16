#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s;
    cin >> s;
    int n = (int) s.length();
    if (n <= 2) {
        cout << "YES";
    } else {
        bool ok = 1;
        for (int i = 2; i < n; i++) {
            int a = s[i] - 'A';
            int b = s[i - 1] - 'A';
            int c = s[i - 2] - 'A';
            ok &= ((b + c - a + 26) % 26 == 0);
        }
        cout << (ok ? "YES" : "NO");
    }   
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}