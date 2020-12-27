#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n, m;
  cin >> n >> m;
  bool ok_2 = 0;
  for(int i = 0; i < n; i++) {
    vector<int> ar(4);
    for(int j = 0; j < 4; j++) {
      cin >> ar[j];
    }
    ok_2 |= (ar[1] == ar[2]);
  }
  if(ok_2 & (!(m & 1))) {
    cout << "YES";
  } else {
    cout << "NO";
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