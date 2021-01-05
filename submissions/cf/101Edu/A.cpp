#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  int len = (int) s.length();
  if (s[len - 1] == '(' || s[0] == ')' || (len % 2 == 1)) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  cout << '\n';
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