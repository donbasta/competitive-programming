#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int ask(ll x) {
  int lol;
  cout << "? " << x << endl;
  cin >> lol;
  return lol;
}

void answer(ll x) {
  cout << "= " << x << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    ll n;
    cin >> n;
    ll lo = 1, hi = n, ans = -1;
    while(lo <= hi) {
      ll mid = (lo + hi) >> 1;
      int que = ask(mid);
      if(que == 1) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    answer(ans);
  }
  
  return 0;
}