#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n;
  cin >> n;

  int a[n + 1], b[n + 1];
  map<int, int> mp;
  for(int i = 1; i <= n; i++) {
  	int x;
  	cin >> x;
  	a[x] = i;
  }
  for(int i = 1; i <= n; i++) {
  	int x;
  	cin >> x;
  	b[x] = i;
  }
  for(int i = 1; i <= n; i++) {
  	int beda = b[i] - a[i];
  	if(beda < 0) beda += n;
  	mp[beda]++;
  }
  int mx = 0;
  for(auto i : mp) {
  	mx = max(i.second, mx);
  }
  cout << mx << '\n';
  return 0;
}
