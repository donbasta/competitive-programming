#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 1e9;

void solve() {
  int n;
  cin >> n;
  vector<int> ar(n), h(n+1, INF);
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  queue<int> q;
  q.emplace(1);
  h[1] = 0;
  for (int i = 1; i < n; i++) {
    if (ar[i] <= ar[i-1]) {
      q.pop();
    }
    h[ar[i]] = h[q.front()] + 1;
    q.emplace(ar[i]);
  }
  int dep = *max_element(++h.begin(), h.end());
  cout << dep << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  cin >> TC;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}