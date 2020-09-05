#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string a, b;

void solve() {
  cin >> a >> b;
  int sa = (int)a.size(), sb = (int)b.size();
  int i = sa, j = sb;
  --i, --j;
  int ans = 0;
  while(i >= 0 && j >= 0 && a[i] == b[j]) {
    ans++;
    --i, --j;
  }
  cout << sa + sb - 2 * ans << '\n';
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