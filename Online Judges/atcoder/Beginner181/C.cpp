#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e2 + 5;

ll x[N], y[N];

bool coll(int a, int b, int c) {
  return ((x[a]-x[b]) * (y[a]-y[c]) == (x[a]-x[c]) * (y[a]-y[b]));
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if (coll(i, j, k)) {
          cout << "Yes" << '\n';
          return;
        }
      }
    }
  }
  cout << "No" << '\n';
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