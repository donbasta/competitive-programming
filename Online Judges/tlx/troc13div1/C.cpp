#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 1e4 + 69;

int n, mx = -1, ans = -1;
int d[N];
ll sum;
vector<ll> fact;

int f(ll a) {

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> d[i];
    mx = max(mx, d[i]);
    sum = sum + d[i];
  }
  for()
  for(ll i = 1; i * i <= sum; i++) {
    if(sum % i == 0) {
      fact.push_back(i);
      if(i != sum / i)
        fact.push_back(sum / i);
    }
  }
  sort(fact.begin(), fact.end());
  for(int i = 0; i < (int)fact.size(); i++) {
    if(fact[i] < mx)
      continue;
    int lol = f(fact[i]);
    if(ans == -1 && lol >= 0)
      ans = lol;
    else if(ans >= 0 && lol >= 0)
      ans = min(ans, lol);
  }
  cout << ans << '\n';
  return 0;
}
