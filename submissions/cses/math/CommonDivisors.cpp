#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e6;

int cnt[N + 5], tot[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for(int i = 1; i <= N; i++) {
    for(int j = i; j <= N; j += i) {
      tot[i] += cnt[j];
    }
  }
  int mx = -1;
  for(int i = 1; i <= N; i++) {
    if(tot[i] >= 2) mx = i;
  }
  cout << mx << '\n';  
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