#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int M = 50;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(2 * M + 1, 0);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int ans = -1;
  for(int i = 2; i <= 100; i++) {
    int temp = 0;
    for(int j = 1; j + j <= i; j++) {
      if(j + j == i) {
        temp += cnt[j] / 2; 
        continue;
      }
      temp += min(cnt[j], cnt[i - j]);
    }
    ans = max(ans, temp);
  }
  cout << ans << '\n';
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