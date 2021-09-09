#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
string s, ss;

void solve() {
    cin >> n;
    cin >> s;
    ss = s;
    sort(ss.begin(), ss.end());
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ss[i]) k++;
    }
    cout << k << '\n';
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