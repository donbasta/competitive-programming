#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, one, idx = -1;
string s;

void solve(int pos) {
  int cntBit = one;
  int ret = 0;
  if(s[pos] == '0')
    cntBit++;
  else
    cntBit--;
  if(cntBit == 0) {
    cout << ret << '\n';
    return;
  }
  int pw2 = 1;
  int cur = 0;
  for(int i = n - 1; i >= 0; i--) {
    int bit = s[i] - '0';
    if(i == pos)
      bit ^= 1;
    cur = (1LL * cur + 1LL * pw2 * (bit)) % cntBit;
    pw2 = (1LL * pw2 * 2) % cntBit;
  }
  ret++;
  while(cur > 0) {
    int lol = __builtin_popcount(cur);
    cur %= lol;
    ret++;
  }
  cout << ret << '\n';
}

int main() {
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    one += (s[i] == '1');
    idx = i;
  }
  for(int i = 0; i < n; i++) {
    solve(i);
  }
  return 0;
}