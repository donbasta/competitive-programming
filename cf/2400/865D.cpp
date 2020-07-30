#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(!pq.empty()) {
      if(pq.top() < x) {
        ans += x - pq.top();
        pq.pop();
        pq.push(x);
      }
    }
    pq.push(x);
  }
  cout << ans << '\n';
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