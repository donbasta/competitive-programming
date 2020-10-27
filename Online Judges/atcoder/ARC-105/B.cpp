#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  } 
  int fpb = ar[0];
  for(int i = 1; i < n; i++) {
    fpb = __gcd(fpb, ar[i]);
  }
  cout << fpb << '\n';
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