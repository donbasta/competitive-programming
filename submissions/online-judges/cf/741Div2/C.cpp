#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    int ze = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            ze = i;
            break;
        }
    }
    if (ze == -1) {
        cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
    } else if (ze >= n / 2) {
        cout << 1 << ' ' << ze + 1 << ' ' << 1 << ' ' << ze << '\n';
    } else {
        cout << ze + 1 << ' ' << n << ' ' << ze + 2 << ' ' << n << '\n';
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