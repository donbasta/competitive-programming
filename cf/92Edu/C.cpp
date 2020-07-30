#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string s;

bool samasemua(string ss) {
  int len = (int)ss.length();
  if(len <= 1) return true;
  bool ok = true;
  char cek = ss[0];
  for(int i = 1; i < len; i++) {
    ok &= (ss[i] == cek);
  }
  return ok;
}

void solve() {
  int ans = -1;
  cin >> s;
  int le = (int)s.length();
  for(int i = 0; i < 10; i++) {
    for(int j = i; j < 10; j++) {
      string temp = "";
      int cur = -1;
      for(auto dig : s) {
        int now = dig - '0';
        if(now == i || now == j) {
          if(i != j) {
            if(now != cur) {
              temp += dig;
              cur = now;
            }
          } else {
            temp += dig;
          }
        }
      }
      int lol = (int)temp.length();
      if(lol == 0) continue;
      if(lol & 1) {
        if(samasemua(temp)) ans = max(ans, lol);
        else ans = max(ans, lol - 1);
      } else {
        ans = max(ans, lol);
      }
    }
  }
  cout << le - ans << '\n';
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