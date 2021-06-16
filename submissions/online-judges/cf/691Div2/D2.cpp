#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100;

struct gelas {
  int a, b;
  bool operator<(gelas other) {
    if (b > other.b) return true;
    else if (b < other.b) return false;
    return (a > other.a);
  }
} g[N + 5];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> g[i].a >> g[i].b;
  }
  sort(g + 1, g + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int )
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