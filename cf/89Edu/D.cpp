#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e7;

int n, lpf[N + 69];
vector<pair<int, int>> ans;

void prec() {
  lpf[1] = 1;
  for(int i = 2; i <= N; i++) {
    if(lpf[i] != 0)
      continue;
    for(int j = i; j <= N; j += i){
      if(lpf[j] != 0)
        continue;
      lpf[j] = i;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  prec();
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    vector<int> primes;
    while(x > 1) {
      int p = lpf[x];
      primes.push_back(p);
      while(x % p == 0)
        x /= p;
    }
    int sz = (int)primes.size();
    if(sz <= 1)
      ans.emplace_back(-1, -1);
    else {
      int a = primes[0];
      int b = 1;
      for(int j = 1; j < sz; j++) {
        b *= primes[j];
      }
      ans.emplace_back(a, b);
    }
  }
  for(auto i : ans)
    cout << i.first << ' ';
  cout << '\n';
  for(auto i : ans)
    cout << i.second << ' ';
  cout << '\n';
  return 0;
}
