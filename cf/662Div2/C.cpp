#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;
vector<int> cnt;

void solve() {
  cin >> n;
  cnt.assign(n, 0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x; --x;
    cnt[x]++;
  }
  sort(cnt.begin(), cnt.end(), greater<int>());
  int mx = cnt[0];
  int num = 1, numMx = 1;
  while(num < n && cnt[num] == mx) {
    numMx++;
    num++;
  }
  int Ans = (n - numMx) / (mx - 1) - 1;
  cout << Ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}