#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

ll fastpow(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1) {ret = ret * a % MOD;}
    a = a * a % MOD;;
    b >>= 1;
  }
  return ret;
}

void solve() {
  
  ll ar[200000];
  ar[0] = 1;
  ar[1] = 2;
  ar[2] = 12;
  ar[3] = 40;
  ar[4] = 144;
  for(int i = 5; i < 100000; i++) {
    ar[i] = (4 * ar[i - 1] - 8 * ar[i - 3]) % MOD;
  }
  ll temp = 0;
  int now;
  cin >> now;
  for(int j = 1; j <= now; j++) {
    temp += fastpow(2, j + 1) * ar[now - j];
    temp %= MOD;
  }
  temp += 8 * ar[now - 2];
  temp %= MOD;
  if(temp < 0) temp += MOD;
  cout << temp;
  cout << '\n';
  

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