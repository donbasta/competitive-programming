#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> s;
  for(int i = 1; i < n; i++) {
    int a = s[i] - 'a', b = s[i + 1] - 'a';
    if(a == b)
      continue;
    if(a > b)
      swap(a, b);
    cnt[a][b]++;
  }
  for(int i = 0; i < m; i++) {
    for(int j = i + 1; j< m; j++) {
      if(cnt[i][j] == 0) continue;
      
    }
  }

  return 0;
}
