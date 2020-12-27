#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5 + 2;

int n;
int ar[3 * N];
priority_queue<int, vector<int>, greater<int>> p1;
priority_queue<int> p2;
ll sum1, sum2, ans = -1e18;
ll mx[3 * N], mn[3 * N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 1; i <= 3 * n; i++) {
    cin >> ar[i];
  }
  for(int i = 1; i <= n; i++) {
    p1.push(ar[i]);
    sum1 += ar[i];
  }
  // cerr << p1.top() << ":D\n";
  mx[n] = sum1;
  for(int i = n + 1; i <= 2 * n; i++) {
    sum1 += ar[i];
    p1.push(ar[i]);
    sum1 -= p1.top();
    // cerr << i << ' ' << p1.top() << '\n';
    p1.pop();
    mx[i] = max(mx[i - 1], sum1);
  }
  for(int i = 3 * n; i >= 2 * n + 1; i--) {
    p2.push(ar[i]);
    sum2 += ar[i];
  }
  mn[2 * n + 1] = sum2;
  for(int i = 2 * n; i >= n + 1; i--) {
    sum2 += ar[i];
    p2.push(ar[i]);
    sum2 -= p2.top();
    p2.pop();
    mn[i] = min(mn[i + 1], sum2);
  }
  for(int i = n; i <= 2 * n; i++) {
    // cerr << mx[i] << ' ' << mn[i + 1] << '\n';
    ans = max(ans, mx[i] - mn[i + 1]);
  }
  cout << ans << '\n';
  return 0;
}