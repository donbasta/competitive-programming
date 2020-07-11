#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int wi(ll a, ll b);
int lo(ll a, ll b);

int wi(ll a, ll b) {
  if(a > (b / 2)) {
    if((b - a) & 1)
      return 1;
    else 
      return 2;
  } else {
    if(b & 1) {
      if(a & 1)
        return 2;
      else
        return 1;
    } else {
      return lo(a, b / 2);
    }
  }
}

int lo(ll a, ll b) {
  if(a > b / 2)
    return 1;
  else {
    return wi(a, b / 2);
  }
}

const int N = 1e5 + 69;

int win[N], lose[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i++) {
    ll s, e;
    cin >> s >> e;
    win[i] = wi(s, e);
    lose[i] = lo(s, e);
  }
  int cur = win[tc];
  int cur2 = lose[tc];
  for(int i = tc - 1; i >= 1; i--) {
    if(cur == 1) {
      cur = lose[i];
    } else {
      cur = win[i];
    }
    if(cur2 == 1) {
      cur2 = lose[i];
    } else {
      cur2 = win[i];
    }
  }
  // for(int i = 1; i <= tc; i++) {
  //   cout << win[i] << ' ' << lose[i] << '\n';
  // }
  cout << (cur == 1 ? 1 : 0);
  cout << ' ';
  cout << (cur2 == 1 ? 1 : 0);
  cout << '\n';
  return 0;
}
