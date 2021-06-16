#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string b;

void solve() {
    cin >> n;
    cin >> b;
    string a;
    a.push_back('1');
    int last = 1 + (int) (b[0] - '0');
    for (int i = 1; i < n; i++) {
        int now = (int) (b[i] - '0');
        if (1 + now != last) {
            a.push_back('1');
            last = 1 + now;
        } else {
            a.push_back('0');
            last = now;
        }
    }
    cout << a << '\n';
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