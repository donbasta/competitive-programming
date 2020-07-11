#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ld k, n, prod;

ld f(ld x) {
  return (1 + (ld) (k * k - k) / (ld) (x * (x + 1)));
}

ld init() {
  ld ret = 1;
  for(int i = 1; i < k; i++) {
    ret = ret * (ld) i / (ld) (k + i);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  k = 1000;
  n = k;
  prod = init();
  cerr << prod << '\n';
  int tot = 0;
  while(tot < (int) 1e8 && prod < (ld) 0.5) {
    tot++;
    n = n + 1.0;
    prod = prod * f(n);
  }
  cout << tot << '\n';
  cout << fixed << setprecision(1000) << prod << '\n';
  return 0;
}
