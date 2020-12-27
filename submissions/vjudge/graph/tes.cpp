#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> ve = {3,4,6,7,8,9,12,15,16,18};
  ll ans = 0;
  for(auto i : ve) {
    ans += (1LL << i);
  }
  cout << ans << '\n';
  cout << ans / 9 << '\n';
  cout << ans % 9 << '\n';

  ll lol = 40614;
  while(lol > 0) {
    if(lol & 1) {
      cout << 1;
    }
    else cout << 0;
    lol /= 2;
  }
  
  return 0;
}