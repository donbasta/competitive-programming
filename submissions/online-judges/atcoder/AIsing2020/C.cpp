#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int calc(int a, int b, int c) {
  return a * a + b * b + c * c + a * b + b * c + c * a;
}

int main() {

  int n;
  cin >> n;
  vector<ll> cnt(n + 1, 0);
  for(int i = 1; i * i <= n; i++) {
    for(int j = 1; j * j <= n; j++) {
      for(int k = 1; k * k <= n; k++) {
        int lol = calc(i, j, k);
        if(lol <= n) {
          cnt[lol]++;
        }
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    cout << cnt[i] << '\n';
  }
  
  return 0;
}