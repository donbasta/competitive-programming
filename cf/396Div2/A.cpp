#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

string s, t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> s >> t;
  int ss = (int)s.length();
  int tt = (int)t.length();

  if(ss != tt) 
    cout << max(ss, tt);
  else {
    if(s != t)
      cout << ss;
    else 
      cout << -1;
  }
  cout << '\n';
  return 0;
}
