#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
  cin >> n;
  vector<int> ar(n);
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int mx = *max_element(ar.begin(), ar.end());
  bool ok = true;
  int val = -1;
  for(int i = 1; i < n; i++) {
    int temp = abs(ar[i] - ar[i - 1]);
    if(temp == 1) continue;
    if(temp == 0) {ok = false; break;}
    if(val == -1) val = temp;
    else {
      if(val != temp) {ok = false; break;}
    }
  }
  if(val == -1 && ok) {
    cout << "YES" << '\n';
    cout << 1 << ' ' << mx << '\n';
    return;
  }
  int y = val;
  for(int i = 1; i < n; i++) {
    int temp = abs(ar[i] - ar[i - 1]);
    if(temp == 1) {
      int a = max(ar[i], ar[i - 1]);
      int b = min(ar[i], ar[i - 1]);
      if(a % y == 1) ok = false;
    }
  }
  if(!ok) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  int x = (mx + y - 1) / y;
  cout << x << ' ' << y << '\n';
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