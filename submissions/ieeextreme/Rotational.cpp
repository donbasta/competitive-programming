#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

int KMP(const vector<long long>& dif) {
  int i, j;
  int P[n+1];
  P[0] = -1, i = 1, j = -1;
  while(i < n) {
    while(j >= 0 && dif[j+1] != dif[i])
      j = P[j];
    if(dif[j+1] == dif[i])
      ++j;
    P[i] = j, ++i;
  }
  return j;
}
int main() {
  long long T;
  cin >> n >> T;
  vector<long long> ar(n);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  vector<long long> dif(n);
  for(int i = 0; i < n; i++) {
    int ni = (i+1) % n;
    long long cur = ar[ni]-ar[i];
    if(cur < 0) cur += T;
    dif[i] = cur;
  }
  int t = KMP(dif);
  int len = -1;
  if(n%(n-t-1))
    len = n;
  else
    len = n-t-1;
  ll ans = 0;
  for(int i = 0; i < len; i++) {
    ans += dif[i];
  }
  cout << ans-1 << '\n';
  
  return 0;
}