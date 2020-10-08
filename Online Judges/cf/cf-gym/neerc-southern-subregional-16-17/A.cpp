#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e4;

string ans[N + 5];

void solve() {
  int n;
  cin >> n;
  vector<int> r(n);
  priority_queue<pair<int, int>> pq;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> r[i];
    sum += r[i];
    pq.emplace(r[i], i);
  }
  sort(r.begin(), r.end());
  if(n == 2) {
    if(r[0] == r[1]) {
      cout << r[0] << '\n' << 0 << '\n';
      return;
    } else {
      cout << 0 << '\n' << r[1] << '\n';
      for(int i = 0; i < r[1]; i++) {
        cout << "11" << '\n';
      }
      return;
    }
  }
  assert(n > 2);
  int R = min(r[0], (sum - 2 * r[n - 1]) / (n - 2));
  R = max(R, 0);
  int pointLost = (sum - n * R);
  if(pointLost == 0) {
    cout << r[0] << '\n';
    cout << 0 << '\n';
    return;
  }
  assert(pointLost > 1);
  cout << R << '\n';
  int t = 0;
  if(pointLost & 1) {
    string now(n, '0');
    auto mx = pq.top(); pq.pop();
    auto mx2 = pq.top(); pq.pop();
    auto mx3 = pq.top(); pq.pop();
    int mxf = max(mx.first - 1, 0); pq.emplace(mxf, mx.second);
    int mx2f = max(mx2.first - 1, 0); pq.emplace(mx2f, mx2.second);
    int mx3f = max(mx3.first - 1, 0); pq.emplace(mx3f, mx3.second);
    now[mx.second] = '1';
    now[mx2.second] = '1';
    now[mx3.second] = '1';
    ans[t++] = now;
  }
  while(pq.top().first > R) {
    string now(n, '0');
    auto mx = pq.top(); pq.pop();
    auto mx2 = pq.top(); pq.pop();
    int mxf = max(mx.first - 1, 0); pq.emplace(mxf, mx.second);
    int mx2f = max(mx2.first - 1, 0); pq.emplace(mx2f, mx2.second);
    now[mx.second] = '1';
    now[mx2.second] = '1';
    ans[t++] = now;
  }
  assert(t <= 10000);
  cout << t << '\n';
  for(int i = 0; i < t; i++) {
    cout << ans[i] << '\n';
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