#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int dist(int p, int q, int r, int s) {
  return abs(p - r) + abs(q - s);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    int a, b, n, ans = 0;
    cin >> a >> b >> n;
    if(a == 0) {
      ans = (abs(b) / n) + 1;
      if(b < 0) {
        for(int cur = b; cur <= 0; cur += n) {
          cout << 0 << ' ' << cur + n - 1 << ' ' << n - 1 << ' ' << cur << '\n';
        }
      } else {
        for(int cur = b; cur >= 0; cur -= n) {
          cout << 0 << ' ' << cur << ' ' << n - 1 << ' ' << cur - n + 1 << '\n'; 
        }
      }
    } else if(b == 0) {
      ans = (abs(a) / n) + 1;
      if(a < 0) {
        for(int cur = a; cur <= 0; cur += n) {
          cout << 0 << ' ' << cur + n - 1 << ' ' << n - 1 << ' ' << cur << '\n';
        }
      } else {
        for(int cur = a; cur >= 0; cur -= n) {
          cout << 0 << ' ' << cur << ' ' << n - 1 << ' ' << cur - n + 1 << '\n'; 
        }
      }
    } else {
      int sa = a / abs(a), sb = b / abs(b);
      a = abs(a), b = abs(b);
      ans = max(1 + a / n, 1 + b / n);
      if(dist(a, b, ans * n - 1, ans * n - 1) <= ans - 2) {
        ans++;
      }
      cout << ans << '\n';
      vector<vector<int>> lol;
      int curRow = b, curCol = a;
      int prevBound = (ans - 1) * n - 1;
      for(int i = 0; i < ans; i++) {
        if(curRow <= prevBound) {
          lol.push_back({prevBound + 1, curRow + - n + 1, prevBound + n, curRow});
          prevBound -= n;
        } else if(curCol <= prevBound) {
          lol.push_back({curCol - n + 1, prevBound + 1, curCol, prevBound + n});
        } else {  
          
        }
      }
    }
    cout << '\n';
  }
  
  return 0;
}