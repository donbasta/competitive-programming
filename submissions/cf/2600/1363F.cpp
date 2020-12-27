#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string temp_s, temp_t;
  temp_s = s, temp_t = t;
  sort(temp_s.begin(), temp_s.end());
  sort(temp_t.begin(), temp_t.end());
  if(temp_t != temp_s) {
    cout << -1 << '\n';
    return;
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