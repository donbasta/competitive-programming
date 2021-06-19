#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
string s;

void solve() {
    cin >> n >> k >> s;
    int rep = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] < s[i % rep]) {
            rep = i + 1;
        } else if (s[i] > s[i % rep]) {
            break;
        }
    }
    int cnt = 0;
    for (int i = 0; cnt < k; i = (i + 1) % rep) {
        cout << s[i];
        cnt++;
    }
    cout << '\n';
    return;
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