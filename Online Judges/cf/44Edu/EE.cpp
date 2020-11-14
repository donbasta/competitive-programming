#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int N = 5e5 + 10;
 
ll bit[N], ar[N];
bool can[N];
ll n, k, d;
 
void add(int x, ll val) {
  while (x <= n) {
    bit[x] += val;
    x += x & (-x);
  }
}
 
ll get(int x) {
  ll ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= x & (-x);
  }
  return ret;
}
 
int get(int l, int r) {
  return get(r) - get(l-1);
}
 
void solve() {
  cin >> n >> k >> d;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  } 
  sort(ar, ar + n);
  if (ar[k-1] - ar[0] > d) {
    cout << "NO" << '\n';
    return;
  }
  add(k, 1);
  can[k-1] = 1;
  for (int i = k; i < 2*k - 1; i++) {
    if (ar[i] - ar[0] <= d){
      can[i] = 1;
      add(i+1, 1);
    }
  }
  for (int i = 2*k - 1; i < n; i++) {
    int r1 = i + 1 - k;
    int r2 = lower_bound(ar, ar+n, ar[i]-d) - ar + 1;
    if (r2 > r1 + 1) continue;
    // if (k > r1) continue;
    int que = get(k, r1);
    if (que > 0) {
      can[i] = 1;
      add(i + 1, 1);
    }
  }
  cout << (can[n-1] ? "YES" : "NO") << '\n';
  return;
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