#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
int n;
int ar[N];
 
int getNum(const char& CC) {
  if (isdigit(CC))
    return (CC - '0');
  else
    return (CC - 'A') + 10;
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    // string s; cin >> s;
    // ar[i] = getNum(s[0]) * 16 + getNum(s[1]);
    cin >> ar[i];
  }
  dp[1] = ar[1];
  len[1] = 1;
  for(int i = 2; i <= n; i++) {
    if(len[i - 1] == ar[i]) {
      dp[i] = dp[i - 1];
      len[i] = len[i - 1];
    }
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


