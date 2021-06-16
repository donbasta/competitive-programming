#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;

int ar[N + 5];
int pre[N + 5];
int n, q;

void solve() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    pre[i] = pre[i - 1] ^ ar[i];
  }
  while(q--) {
    int a, b;
    cin >> a >> b;
    cout << (pre[b] ^ pre[a - 1]) << '\n';
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