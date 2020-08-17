#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e3;

string s[N + 5];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for(int i = 0; i < 7; i++) {
    int temp = 0;
    for(int j = 0; j < n; j++) {
      temp += (s[j][i] - '0');
    }
    ans = max(ans, temp);
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