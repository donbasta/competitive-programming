#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n/2);
  for (int i = 0; i < (n/2); i++) {
    cin >> p[i];
    p[i]--;
  }
  sort(p.begin(), p.end());
  int ans = INF;
  for (int t = 0; t < 2; t++) {
    int temp = 0;
    for (int i = 0; i < (n/2); i++) {
      temp += abs(p[i] - (2*i + t));
    }
    ans = min(ans, temp);
  }
  cout << ans << '\n';
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