#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

bool pr[N + 5];

void sieve() {
  fill(pr + 2, pr + N + 1, 1);
  for(int i = 2; i <= N; i++) {
    if(!pr[i]) continue;
    for(int j = i * 2; j <= N; j += i) {
      pr[j] = 0;
    } 
  }
}

void solve() {
  sieve();
  int n;
  cin >> n;
  vector<int> ans;
  for(int i = 2; i <= n; i++) {
    if(!pr[i]) continue;
    int temp = i;
    while(temp <= n) {
      ans.push_back(temp);
      temp *= i;
    }
  }
  cout << (int)ans.size() << '\n';
  for(auto i : ans) { cout << i << ' '; }
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