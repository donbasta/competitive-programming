#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

bool match(string s1, string s2) {
  int len1 = (int)s1.length();
  int len2 = (int)s2.length();
  if(len1 != len2) {
    return false;
  }
  bool ok = true;
  for(int i = 0; i < len1; i++) {
    ok &= ((s2[i] == '?') || (s1[i] == s2[i]));
  }
  return ok;
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s[n];
  int ve[m];
  vector<bool> del(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> ve[i];
    --ve[i];
    del[ve[i]] = true;
  }
  int len = (int) s[ve[0]].length();
  bool ok = true;
  for(int i = 1; i < m; i++) {
    ok &= (len == (int) s[ve[i]].length());
  }
  if(!ok) {
    cout << "No" << '\n';
    return;
  }
  string pattern(len, ' ');
  for(int i = 0; i < len; i++) {
    bool same = true;
    char c = s[ve[0]][i];
    for(int j = 1; j < m; j++) {
      same &= (c == s[ve[j]][i]);
    }
    if(same) {
      pattern[i] = c;
    } else {
      pattern[i] = '?';
    }
  }
  for(int i = 0; i < n; i++) {
    if(del[i]) continue;
    if(match(s[i], pattern)) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
  cout << pattern << '\n';
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