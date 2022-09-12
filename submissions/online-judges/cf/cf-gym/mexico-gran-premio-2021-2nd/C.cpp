#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> R(n + 1), B(n + 1);
    for (int i = 0; i < n; i++) {
        R[i + 1] = R[i], B[i + 1] = B[i];
        if (s[i] == 'R') {
            R[i + 1]++;
        } else {
            B[i + 1]++;
        }
    }
    int mn = 1e9, idx = -1;
    for (int i = 0; i <= n; i++) {
        if (B[i] - R[i] < mn) {
            mn = B[i] - R[i], idx = i;
        }
    }
    cout << idx << '\n';
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