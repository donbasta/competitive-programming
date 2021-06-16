#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for(auto& c : s) {cnt[(int) c - 'A']++;}
  int odd = 0, mid = -1;
  for(int i = 0; i < 26; i++) {
    if(cnt[i] & 1) {odd++; mid = i;}
  }
  if(odd > 1) {
    cout << "NO SOLUTION" << '\n';
    return;
  }
  for(int i = 0; i < 26; i++) {
    if(i == mid) continue;
    for(int j = 0; j < cnt[i] / 2; j++) {
      cout << (char) (i+ 'A');
    } 
  }
  if(mid != -1) {
    for(int i = 0; i < cnt[mid]; i++) {
      cout << (char) (mid + 'A');
    }
  }
  for(int i = 25; i >= 0; i--) {
    if(i == mid) continue;
    for(int j = 0; j < cnt[i] / 2; j++) {
      cout << (char) (i + 'A');
    } 
  }
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