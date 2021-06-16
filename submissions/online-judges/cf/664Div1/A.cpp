#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  cin >> n >> d >> m;
  vector<int> a(n);
  int small = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] <= m) {
  }
  sort(a.begin(), a.end(), greater<ll>());
  for(int i = n - 1; i >= 0; i--) {
    if(a[i] > m) break;
    sm++;
    pre[]
  }
  ll rest = (n - sm + d) / (d + 1);
  for(int i = 0; i < rest; i++) {
    ans += a[i];
  }
  int need = d + 1 - 
  for(int i = rest; i < n; i++) {
    int need = 
    if(a[])
  }

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