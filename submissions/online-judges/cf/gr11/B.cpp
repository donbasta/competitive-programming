#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, k;
string s;

void solve() {
  cin >> n >> k;
  cin >> s;
  int lose = 0;
  int skor = 0;
  for(int i = 0; i < n; i++) {
    lose += (s[i] == 'L');
    if(s[i] == 'W') {
      if(i == 0) skor++;
      else {
        if(s[i - 1] == 'W') skor += 2;
        else skor++;
      }
    }
  }
  if(k == 0) {
    cout << skor << '\n';
    return;
  }
  if(lose == n) {
    cout << 2 * k - 1 << '\n';
    return;
  }
  if(lose <= k) {
    int ans = 2 * n - 1;
    cout << ans << '\n';
    return;
  }
  int cur = 0;
  vector<int> ve;
  bool found = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'W') {
      if(found)
        if(cur > 0) ve.push_back(cur);
      cur = 0;
      found = 1;
    }
    if(s[i] == 'L') {
      cur++;
    }
  }
  // cerr << (int)ve.size() << '\n';
  sort(ve.begin(), ve.end());
  int temp = 0;
  for(int i = 0; i < (int)ve.size(); i++) {
    int lul = temp + ve[i];
    if(lul > k) {
      skor += 2 * (k - temp);
      temp = k;
      break;
    } else {
      temp = lul;
      skor += 1 + 2 * ve[i];
    }
  }
  if(temp < k) {
    skor += 2 * (k - temp);
  }
  cout << skor << '\n';
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