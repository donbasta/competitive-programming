#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int t;
  // cin >> t;
  t=1;
  while(t--) {
    ll a, b;
    cin >> a >> b;
    ll p = 1, ans = 0;
    while(p * 10 - 1 <= b) {
      p *= 10;
      ++ans;
    }
    cout << a * ans << "\n";
  }
}