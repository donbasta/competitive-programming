#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool isNumber(char c) {
  int t = c - '0';
  return (t >= 0 && t <= 9);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("easy.in", "r", stdin);
  freopen("easy.out", "w", stdout);

  string tok;
  cin >> tok;
  int sz = (int) tok.length();
  vector<int> pos;
  bool cur = false;
  for(int i = 0; i < sz; i++) {
    if(tok[i] == '-') {
      cur = true;
    } else {
      if(cur && (i < sz - 1) && isNumber(tok[i + 1])) {
        if(i < sz - 2 && tok[i + 1] == '0' && isNumber(tok[i + 2])) //leading zero
          pos.push_back(i);
        else{
          pos.push_back(i);
          cur = false;
        }
      } else {
        cur = false;
      }
    }
  }
  string ans = "";
  int now = 0;
  int len = (int) pos.size();
  for(int i = 0; i < sz; i++) {
    ans += tok[i];
    if(now < len && pos[now] == i) {
      ans += '+';
      now++;
    }
  }
  cout << ans << '\n';

  return 0;
}
